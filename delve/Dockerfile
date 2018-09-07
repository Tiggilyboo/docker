FROM tiggilyboo/go
MAINTAINER Simon Willshire <me@simonwillshir.com>
LABEL description="Delve Go Debugger"

RUN \
  go get github.com/derekparker/delve/cmd/dlv && \
  go install github.com/derekparker/delve/cmd/dlv

CMD ["dlv", "-h"]
