#!/bin/bash

wellcome() {
    echo "########  ##     ## #### ##       ########          ########  ########   #######        ## ########  ######  ######## "
    echo "##     ## ##     ##  ##  ##       ##     ##         ##     ## ##     ## ##     ##       ## ##       ##    ##    ##    "
    echo "##     ## ##     ##  ##  ##       ##     ##         ##     ## ##     ## ##     ##       ## ##       ##          ##    "
    echo "########  ##     ##  ##  ##       ##     ## ####### ########  ########  ##     ##       ## ######   ##          ##    "
    echo "##     ## ##     ##  ##  ##       ##     ##         ##        ##   ##   ##     ## ##    ## ##       ##          ##    "
    echo "##     ## ##     ##  ##  ##       ##     ##         ##        ##    ##  ##     ## ##    ## ##       ##    ##    ##    "
    echo "########   #######  #### ######## ########          ##        ##     ##  #######   ######  ########  ######     ##    "
    
    echo "Hello $USER !!"
}

check_files() {
    local files=("./project.yml"
                 "./team.md"
                 "./src/convert_system.c" 
                 "./src/convert_system.h"
                 "./src/input_run_system.c"
                 "./src/input_run_system.h"
                 "./src/boolesche_Algebra.h"
                 "./src/boolesche_Algebra.c"
                 "./src/scan_boolesche_Algebra.h"
                 "./src/scan_boolesche_Algebra.c"
                 "./src/manager.h"
                 "./src/manager.c"
                 "./src/ieee.c"
                 "./src/ieee.h"
                 "./src/ieee_manager.c"
                 "./src/ieee_manager.h"
                 "./src/spiel.c"
                 "./src/spiel.h"
                 "./src/zurueckwandelnIEEE.c"
                 "./src/zurueckwandelnIEEE.h"
                 "./src/formelrechner.c"
                 "./src/formelrechner.h"
                 "./src/logikgatter_erkennen.c"
                 "./src/logikgatter_erkennen.h"
                 "./src/logikgatter_manager.c"
                 "./src/logikgatter_manager.h"
                 "./src/logikgatter_tabelle.c"
                 "./src/logikgatter_tabelle.h"
                 "./src/menue.c"
                 "./src/menue.h"
                 "./test/test_convert_system.c"
                 "./test/test_boolesche_Algebra.c"
                 "./test/test_scan_boolesche_Algebra.c"
                 "./test/test_manager.c"
                 "./test/test_ieee.c"
                 "./test/test_zurueckwandelnIEEE.c"
                 "./test/test_spiel.c")

    for file in "${files[@]}"; do
        if [[ ! -f "$file" ]]; then
            echo "File $file is missing!"
        fi
    done

    echo "All necessary files exist."

    return 0
}

check_installation() {
    local cmds=("ruby" "gcc" "ceedling")

    for cmd in "${cmds[@]}"; do
        if ! command -v $cmd &> /dev/null; then
            echo "$cmd is not installed."
        else
            echo "$cmd is installed."
        fi
    done
}

compile() {
    gcc -o main src/*.c -lm

    if [[ $? -eq 0 ]]; then
        ./main
    else
        echo "Compilation failed."
    fi
}

remove() {
    rm -r build
    rm main 
}

wellcome

check_files
check_installation

ceedling test:all

compile

remove
