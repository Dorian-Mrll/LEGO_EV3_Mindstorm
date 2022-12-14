#pragma config(Sensor, S1,     Color,          sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S3,     Touch,          sensorEV3_Touch)
#pragma config(Sensor, S4,     Supersonic,     sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Puch,          tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          Tapis1,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          Tapis2,        tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task tapis();
task color();
task touch();
task supersonic();

void move_tapis2(int color);

int change_Color=0;
int etat_tapis=0;


int current_color=0;

int etat_supersonic = 0;

int dist=255;
int hue=0;


task color(){

	while(1){
		hue = getColorHue(S1);

		if(hue >=210 && hue < 240){
			displayBigTextLine(4, "bleu");
			change_Color = 1;
			current_color = 2;
		}
		else if(hue <= 80 && hue != 0){
			displayBigTextLine(4, "jaune");
			change_Color = 1;
			current_color = 4;
		}
		else if(hue >= 330){
			displayBigTextLine(4, "rouge");
			change_Color = 1;
			current_color = 5;
		}
		else if(hue>= 120 && hue<200){
			displayBigTextLine(4, "vert");
			change_Color = 1;
			current_color = 3;
		}
		else
			displayBigTextLine(4, "none");

		if(change_Color){
			wait1Msec(2000);
			change_Color = 0;
			//etat_tapis = 2;
		}
	}
}


task tapis(){

	while(1){

		if(etat_tapis == 1)	setMotorSpeed(motorB, 10);
		else if(etat_tapis ==2) setMotorSpeed(motorB, 60);
		else	setMotorSpeed(motorB, 30);

	}
}



task supersonic(){

	while(1){

		dist = getUSDistance(S4);
		if(dist <= 4)	etat_supersonic = 1;
	}
}



void move_tapis2(int color){

	displayTextLine(3, "color %d", color);
	if(color ==5 || color == 4){
		setMotorSpeed(motorD, 20);
	}
	else if(color ==3 || color ==2){
		setMotorSpeed(motorD, -20);
	}
	else
		setMotorSpeed(motorD, 100);

	wait1Msec(2000);
	etat_tapis = 0;
	etat_supersonic = 0;
	setMotorSpeed(motorD, 0);
	current_color = 0;
}





task touch(){

	while(1){
		if(getTouchValue(S3) == 1){
			moveMotor(motorA, 360, degrees, 60);
		}
	}
}





task main()
{

	startTask(color);
	startTask(tapis);
	startTask(touch);
	startTask(supersonic);

	while(1){

		displayTextLine(1, "change_Color %d", change_Color);
		displayTextLine(2, "dist %d", dist);
		displayBigTextLine(7, "hue %d", hue);
		//if(etat_tapis == 2) move_tapis2(current_color);
		if(etat_supersonic == 1) move_tapis2(current_color);
	}
	stopAllTasks();
}
