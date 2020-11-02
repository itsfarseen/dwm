#!/bin/sh
date >>$HOME/dwm_autostart

# launch only if the exe is not running
# prevents duplicate launches when restarting
function single_instance() {
    exe=$1
    shift 1
    args=$*
    pgrep -laf $(which $exe) || pgrep -laf $exe || $exe $args &
}

single_instance firefox
single_instance notion-app
single_instance dwm-status $HOME/.config/dwm-status.toml
single_instance sxhkd
