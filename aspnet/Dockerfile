FROM tiggilyboo/base
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="ASP.NET Core 2.0"

ENV BUILD_PACKAGES="ca-certificates curl libc6 libcurl3 libgcc1 libgssapi-krb5-2 libicu57 liblttng-ust0 libssl1.1 libstdc++6 libunwind8 libuuid1 zlib1g" \
    DOTNET_SDK_VERSION="2.1.3"
ENV DOTNET_SDK_DOWNLOAD_URL="https://dotnetcli.blob.core.windows.net/dotnet/Sdk/$DOTNET_SDK_VERSION/dotnet-sdk-$DOTNET_SDK_VERSION-linux-x64.tar.gz" \
    NUGET_XMLDOC_MODE="skip" \
    ASPNETCORE_URLS="http://*:80" \
    ASPNETCORE_PKG_VERSION="2.0.3"

RUN apt-get update && \
    apt-get install -yq --no-install-recommends $BUILD_PACKAGES && \
    curl -SL $DOTNET_SDK_DOWNLOAD_URL --output dotnet.tar.gz \
    && mkdir -p /usr/share/dotnet \
    && tar -zxf dotnet.tar.gz -C /usr/share/dotnet \
    && rm dotnet.tar.gz \
    && ln -s /usr/share/dotnet/dotnet /usr/bin/dotnet && \
    apt-get autoremove -y && \
    rm -rf /var/lib/apt/lists && \
    rm -rf /var/cache/apt && \
    mkdir warmup && \
    cd warmup && \
    dotnet new && \
    cd .. && \
    rm -rf warmup && \
    rm -rf /tmp/NuGetScratch && \
    for version in '2.0.0' '2.0.3'; do \
        curl -o /tmp/runtimestore.tar.gz https://dist.asp.net/runtimestore/$version/linux-x64/aspnetcore.runtimestore.tar.gz \
        && export DOTNET_HOME=$(dirname $(readlink $(which dotnet))) \
        && tar -x -C $DOTNET_HOME -f /tmp/runtimestore.tar.gz \
        && rm /tmp/runtimestore.tar.gz; \
    done

CMD ["/bin/bash"]
