rm keymap.json
qmk c2json --no-cpp -kb keychron/q4/iso -km vial_swolemakdh -o keymap.json
keymap parse -q keymap.json >> pretty.yaml
keymap draw -j "../../info.json" pretty.yaml >> keymap.svg