FROM tiggilyboo/base
LABEL description="Caddy HTTPS rproxy"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV DEBIAN_FRONTEND=noninteractive \
    BUILD_PACKAGES="tar curl git wget libcap2-bin ca-certificates openssh-client"

RUN \
  apt-get update && apt-get install --no-install-recommends -y $BUILD_PACKAGES && \
  mkdir -p /config && \
  curl "https://caddyserver.com/download/linux/amd64" | tar --no-same-owner -C /usr/bin/ -xz caddy && \
  /usr/sbin/setcap 'cap_net_bind_Service=+ep' /usr/bin/caddy && \
  apt-get autoremove -y && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt 

EXPOSE 80 443
CMD ["caddy"]
