#!/bin/sh

INPUTTHEME="${1}"
[ -n "${INPUTHEME}" ] || INPUTTHEME="/usr/share/themes/Adwaita"

OUTPUTTHEME="$(dirname $(readlink -fn ${0}))"
OUTPUTNAME="$(basename ${OUTPUTTHEME})"
OUTPUTINDEX="${OUTPUTTHEME}/index.theme"

cp "${INPUTTHEME}/index.theme" "${OUTPUTINDEX}"

INPUTNAME=$(cat "${OUTPUTINDEX}" | grep '^Name=' | sed 's/^[^=]*=//')

sed -i -E "s/(Name.*|GtkTheme)=${INPUTNAME}/\1=${OUTPUTNAME}/" index.theme

cd "${OUTPUTTHEME}"/gtk-color-export
if make; then
    export GTK_THEME="${OUTPUTNAME}"
    GTK_COLOR_SCHEME="$(./gtk-color-export | sed 's/\\/\\\\/g')"
    sed -i "s/^gtk-color-scheme.*\$/$GTK_COLOR_SCHEME/" "${OUTPUTTHEME}/gtk-2.0/gtkrc"
fi
