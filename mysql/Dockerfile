FROM tiggilyboo/base
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="MySQL DB"

ENV INSTALL_PACKAGES="ca-certificates wget pwgen openssl perl  mysql-server" 

RUN groupadd -r mysql && useradd -r -g mysql mysql && \
  mkdir /docker-entrypoint-initdb.d && \
  { \
		echo mysql-community-server mysql-community-server/data-dir select ''; \
		echo mysql-community-server mysql-community-server/root-pass password ''; \
		echo mysql-community-server mysql-community-server/re-root-pass password ''; \
		echo mysql-community-server mysql-community-server/remove-test-db select false; \
	} | debconf-set-selections && \
  apt-get update && \
  apt-get install --no-install-recommends -yq $INSTALL_PACKAGES && \
  rm -rf /var/lib/mysql && mkdir -p /var/lib/mysql /var/run/mysqld && \
  chown -R mysql:mysql /var/lib/mysql /var/run/mysqld && \
  chmod 777 /var/run/mysqld && \
  find /etc/mysql/ -name '*.cnf' -print0 \
		| xargs -0 grep -lZE '^(bind-address|log)' \
    | xargs -rt -0 sed -Ei 's/^(bind-address|log)/#&/' && \
	echo '[mysqld]\nskip-host-cache\nskip-name-resolve' > /etc/mysql/conf.d/docker.cnf && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

VOLUME /var/lib/mysql

COPY docker-entrypoint.sh /usr/local/bin/
RUN ln -s usr/local/bin/docker-entrypoint.sh /entrypoint.sh # backwards compat
ENTRYPOINT ["docker-entrypoint.sh"]

EXPOSE 3306
CMD ["mysqld"]
