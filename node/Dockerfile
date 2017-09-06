FROM tiggilyboo/base
LABEL description="Node"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV VERSION=v8.4.0 \
    BUILD_PACKAGES="apt-utils ca-certificates curl"

RUN apt-get update && \
  apt-get install --no-install-recommends -yq $BUILD_PACKAGES && \
  curl https://nodejs.org/dist/$VERSION/node-$VERSION-linux-x64.tar.gz | tar xz -C /usr/local/ --strip=1 && \
  apt-get remove --allow-remove-essential --purge -y $BUILD_PACKAGES && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

VOLUME /src
WORKDIR /src
