#!/bin/sh

#RYU_GIT="https://github.com/routeflow/ryu-rfproxy.git"
RYU_GIT="https://github.com/vdham/ryu-rfproxy-kamboi.git"
RYU_BRANCH="origin/ldp_v1.1"

RYU_DEPS="python-greenlet python-eventlet python-webob python-routes"
RYU_VERSION="2.0"

get_ryu() {
    if [ "$OVS_VERSION" != "git" ]; then
        print_status "We recommend using ovs-1.10.0 or above with Ryu for OF1.2+ Support" \
            $YELLOW
    fi

    pkg_install "$RYU_DEPS"
    print_status "Fetching Ryu controller"

    if [ $FETCH_ONLY -ne 1 ]; then
        $SUPER pip install oslo.config ryu==$RYU_VERSION ||
            fail "Failed to fetch ryu controller"
    fi

    fetch "ryu-" "rfproxy" $RYU_GIT $RYU_BRANCH ||
        fail "Couldn't fetch ryu-rfproxy"
    git checkout ldp_v1.1
    $DO cd -
}
