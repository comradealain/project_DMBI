
#!/bin/sh

choice=$(zenity --entry --title="Menu" --text="1. Apriori\n2. Bayes\n3. Kmeans\n4. Exit\nEnter your choice:")

  
zenity --info --title="Information" --text="Entered choice: $choice\nThanks for entering. Please refer terminal now."

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
            4) echo "Bye"
            exit
            ;;
		esac

