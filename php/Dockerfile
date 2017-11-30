FROM tiggilyboo/base
LABEL description="PHP 7"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV INSTALL_PACKAGES="ca-certificates curl libargon2-0 libedit2 libsqlite3-0 libxml2 zutils php" 

RUN apt-get update && \
  apt-get install --no-install-recommends -yq $INSTALL_PACKAGES && \
  php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');" && \
  php composer-setup.php && \
  rm composer-setup.php && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

VOLUME /src
WORKDIR /src
