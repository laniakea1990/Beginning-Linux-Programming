#########################################################################
# File Name: ques.sh
# Author: JinRanRan
# mail: jinranran1990910@163.com
# Created Time: Tue 21 Oct 2014 05:56:03 AM PDT
#########################################################################
#!/bin/bash

dialog --title "Questionnaire" --msgbox "Welcome to my simple survey" 9 18
dialog --title "Confirm" --yesno "Are you willing to take part" 9 18

if [ $? != 0 ]; then
	dialog --infobox "Thank you anyway" 5 20
	sleep 2
	dialog --clear
	exit 0
fi

dialog --title "questionnaire" --inputbox "Please enter your name" 9 30 2>_1.txt
Q_NAME=$(cat _1.txt)

dialog --menu "$Q_NAME, what music do you like best?" 15 30 4 1 "Classical" 2 "Jazz" 3 "Country" 4 "Other" 2>_1.txt
Q_MUSIC=$(cat _1.txt)

if [ "$Q_MUSIC" = "1" ]; then
	dialog --title "Likes Classical" --msgbox "Good choice!" 12 25
else
	dialog --title "Doesn't like Classical" --msgbox "Shame" 12 25
fi

sleep 2
dialog --clear
exit 0
