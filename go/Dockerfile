FROM tiggilyboo/base
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="Golang"

ENV DEBIAN_FRONTEND=noninteractive \
    INSTALL_PACKAGES="curl git ca-certificates openssl libssl1.1 g++ gcc libc6-dev make pkg-config" \
    GO_VERSION="1.9" \
    GOPATH="/go" \
    PATH="$PATH:/usr/local/go/bin"

RUN \
  mkdir $GOPATH && cd $GOPATH && \
  apt-get -qq update -qq && \
  apt-get -y -qq --no-install-recommends install $INSTALL_PACKAGES && \
  curl -sL --retry 10 --retry-delay 10 -o /tmp/go$GO_VERSION.linux-amd64.tar.gz \
    https://storage.googleapis.com/golang/go$GO_VERSION.linux-amd64.tar.gz && \
    tar -xzf /tmp/go$GO_VERSION.linux-amd64.tar.gz -C /usr/local && \
  rm -f /tmp/go$GO_VERSION.linux-amd64.tar.gz && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt && \
  cd / && ln -s /home/user/work $GOPATH

CMD ["/bin/bash"]
