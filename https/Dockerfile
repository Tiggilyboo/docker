FROM tiggilyboo/base
LABEL description="Kube-Lego HTTPS"
MAINTAINER Simon Willshire <me@simonwillshire.com>

RUN addgroup -gid 1000 app && \
  adduser --ingroup app --home /home/app -uid 1000 app && \
  apt-get update && \
  apt-get install --no-install-recommends -yq ca-certificates && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

USER app
WORKDIR /home/app

COPY ./kube-lego /kube-lego
ENTRYPOINT ["/kube-lego"]
