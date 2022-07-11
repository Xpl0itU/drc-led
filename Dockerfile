FROM wiiuenv/devkitppc:20220710 AS final

ENV WUT_ROOT=$DEVKITPRO/wut

WORKDIR /
RUN git clone --single-branch https://github.com/Maschell/WiiUPluginSystem && \
 cd WiiUPluginSystem && \
 make -j$(nproc) && \
 make install && \
 cd .. && \
 rm -rf WiiUPluginSystem

WORKDIR /project