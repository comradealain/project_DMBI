#!/bin/sh

echo "Menu "
        echo "1. Apriori"
        echo "2. Bayes"
        echo "3. Kmeans"
        echo "4. Quit"
        echo -n "Enter your choice: "
        read choice
        echo "Entered choice: $choice" 

        case "$choice" in 
        	1) echo "Apriori"
            python Apriori/apriori.py -f Apriori/ap.csv -s 225 -c 0.68
            ;;
            2) echo "Bayes"
            cd B*
            ./b
            ;;
            3) echo "Kmeans"
            cd K*
            ./k2
            ;;
		esac