FROM tiggilyboo/base as builder
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="Gentoo Linux"

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /gentoo

ARG ARCH=amd64
ARG MICROARCH=amd64
ARG SUFFIX
ARG DIST="https://ftp-osl.osuosl.org/pub/gentoo/releases/${ARCH}/autobuilds"
ARG SIGNING_KEY="0xBB572E0E2D182910"

RUN echo "Building ${ARCH} ${SUFFIX} from ${DIST}" && \
  apt update -qq && \
  apt install -yq --no-install-recommends libcurl4-openssl-dev libssl1.1 software-properties-common apt-utils gnupg tar wget xz-utils dirmngr && \
  STAGE3PATH="$(wget -O- "${DIST}/latest-stage3-${MICROARCH}${SUFFIX}.txt" | tail -n 1 | cut -f 1 -d ' ')" && \
  STAGE3="$(basename ${STAGE3PATH})" && \
  wget -q "${DIST}/${STAGE3PATH}" "${DIST}/${STAGE3PATH}.CONTENTS" "${DIST}/${STAGE3PATH}.DIGESTS.asc" && \
  gpg --list-keys && \
  echo "standard-resolver" >> ~/.gnupg/dirmngr.conf && \
  echo "honor-http-proxy" >> ~/.gnupg/dirmngr.conf && \
  echo "disable-ipv6" >> ~/.gnupg/dirmngr.conf && \
  gpg --batch --keyserver ha.pool.sks-keyservers.net --recv-keys ${SIGNING_KEY} && \ 
	gpg --batch --verify "${STAGE3}.DIGESTS.asc" && \
	awk '/# SHA512 HASH/{getline; print}' ${STAGE3}.DIGESTS.asc | sha512sum -c && \
	tar xpf "${STAGE3}" --xattrs --numeric-owner && \
	sed -i -e 's/#rc_sys=""/rc_sys="docker"/g' etc/rc.conf && \
	echo 'UTC' > etc/timezone && \
	rm ${STAGE3}.DIGESTS.asc ${STAGE3}.CONTENTS ${STAGE3}

FROM scratch
WORKDIR /
COPY --from=builder /gentoo/ /
CMD ["/bin/bash"]
