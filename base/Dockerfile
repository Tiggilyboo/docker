FROM scratch
LABEL description="Debian Base Image"
MAINTAINER Simon Willshire <me@simonwillshire.com>
ADD rootfs.tar.xz /

RUN echo 1 > /proc/sys/net/netfilter/nf_conntrack_tcp_be_liberal

CMD ["bash"]
