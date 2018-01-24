FROM tiggilyboo/base
LABEL description="Node & Nvm"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV VERSION=v8.4.0 \
    NVM_VERSION=v0.33.5 \
    NODE_VERSION="lts/boron" \
    NVM_DIR="$HOME/.nvm" \
    BUILD_PACKAGES="apt-utils ca-certificates curl"

RUN apt-get update && \
  apt-get install --no-install-recommends -yq $BUILD_PACKAGES && \
  curl https://nodejs.org/dist/$VERSION/node-$VERSION-linux-x64.tar.gz | tar xz -C /usr/local/ --strip=1 && \
  curl -o- https://raw.githubusercontent.com/creationix/nvm/$NVM_VERSION/install.sh | bash && \
  [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" && \
  [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion" && \
  nvm install lts/boron && \ 
  apt-get remove --allow-remove-essential --purge -y $BUILD_PACKAGES && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

VOLUME /src
WORKDIR /src
