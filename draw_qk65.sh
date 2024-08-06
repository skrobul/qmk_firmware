#!/bin/bash

qmk c2json -km skrobul -kb qwertykeys/qk65/hotswap keyboards/qwertykeys/qk65/hotswap/keymaps/skrobul/keymap.c -o - | keymap parse -q - > keymap_qk65.yaml
keymap draw keymap_qk65.yaml > keymap_qk65.svg

