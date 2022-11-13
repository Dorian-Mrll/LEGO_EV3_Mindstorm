int bool_puch = 0;
int change_Color =0;

task color(){

	while(1){
	/*short codeCouleur =0;
	codeCouleur = getColorName(S1);*/
	int hue = getColorHue(S1);

	/*if(codeCouleur == 2){
			displayTextLine(4, "bleu");
			change_Color = 1;
		}
		else if(codeCouleur == 4){
			displayTextLine(4, "jaune");
			change_Color = 1;
		}
		else if(codeCouleur == 5){
			displayTextLine(4, "rouge");
			change_Color = 1;
		}
		else if(codeCouleur == 3){
			displayTextLine(4, "vert");
			change_Color = 1;
		}
		else{
			displayTextLine(4, "codeCouleur %d", codeCouleur);
		}*/

		if(hue >=210 && hue <= 240){
			displayBigTextLine(4, "bleu");
			change_Color = 1;
		}
		else if(hue <= 80 && hue != 0){
			displayBigTextLine(4, "jaune");
			change_Color = 1;
		}
		else if(hue >= 330){
			displayBigTextLine(4, "rouge");
			change_Color = 1;
		}
		else if(hue>= 120 && hue<200){
			displayBigTextLine(4, "vert");
			change_Color = 1;
		}
		else displayBigTextLine(4, "none");
		displayBigTextLine(7, "hue %d", hue);


		/*if(change_Color){
			wait1Msec(2000);
			change_Color = 0;
		}*/


		}
}



task poussoir(){

	while(1){
		if(getTouchValue(S3) == 1){
			moveMotor(motorA, 360, degrees, 60);
			bool_puch = 1;
		}
		bool_puch = 0;
	}
}




task tapis(){

	while(1){
		setMotorSpeed(motorB, 20);
	}
}



task main()
{
	SensorType[S3] = sensorEV3_Touch;
	SensorType[S1] = sensorEV3_Color;
	setSensorMode(S1, modeEV3Color_Color);


	startTask(tapis);
	startTask(color);
	startTask(poussoir);

	while(1){

		displayTextLine(1, "bool_puch %d", bool_puch);
		displayTextLine(2, "change_Color %d", change_Color);
	}

}
