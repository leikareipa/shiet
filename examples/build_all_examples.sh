# Builds all Kelpo render examples that're residing immediately under this
# directory.

buildScriptName="build_win32_mingw441.sh"

echo "NOTE: Build warnings are suppressed."

for exampleDirectory in $(find ./ -mindepth 1 -maxdepth 1 -type d); do
    if [ -f "$exampleDirectory/$buildScriptName" ]; then
        echo "===== BUILDING $exampleDirectory..."
        (cd "$exampleDirectory" && ./"$buildScriptName" 2>&1 | grep "error")
    fi
done

echo "Done. Asset files will need to be copied manually."