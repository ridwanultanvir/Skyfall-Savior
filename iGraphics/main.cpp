# include "iGraphics.h"
# include "math.h"
# include "stdlib.h"
int mode=0;
double y=30;
double x=700;
double q=30;
double p=800;
double a=900;
double b=30;
double mbx=720;
double mby=-2000;
double blx=900;
double bly=-500;
int arrows=10;
int ok=0;
int prev=0;
int speed=0;
char speeds[100]="0";

int pr=1;
float i=50;
float j=50;
float k=150;
float l=150;
int std=0;
float c;
float m;
double co;
int score=0;
char scores[100]="00000";
char arrowss[100]="10";
int lvl=1;
char lvls[4]="1";
int hs;
char hss[10];
FILE *pt;

void iDraw()
{
	if(mode==0)
	{
		iSetColor(0,0,0);
		iFilledRectangle(0, 0, 1000, 800);
		iShowBMP(0,0, "back1.bmp");
		iShowBMP(350,400, "START.bmp");
		iShowBMP(300,250, "HI.bmp");
		iShowBMP(350,100, "HELP.bmp");
	}
		if(mode==1)
		{
			if(lvl==0)
			{
			iSetColor(0,0,0);
			iFilledRectangle(0, 0, 1000, 800);
			iShowBMP(0,0, "game over.bmp");
			iShowBMP(700,230, "main menu.bmp");
			iShowBMP(735,170, "restart.bmp");
			iShowBMP(745,110, "exit.bmp");

			iSetColor(0,0,255);
			iText(400, 170, scores, GLUT_BITMAP_TIMES_ROMAN_24);
			pt=fopen("hi.txt","r");
			fscanf(pt,"%s",hss);
			fclose(pt);
			hs=atoi(hss);
			if(score>hs)
					{
						hs=score;
						itoa(hs,hss,10);
						pt=fopen("hi.txt","w");
						fprintf(pt,"%s",hss);
						fclose(pt);
					}
			}

			else
			{
			iSetColor(0,0,0);
			iFilledRectangle(0, 0, 1000, 800);


			iSetColor(200,0,100);
			iText(10, 480, "SCORE", GLUT_BITMAP_HELVETICA_18);
			iRectangle(10, 420, 100, 50);
			iSetColor(0,0,0);
			iFilledRectangle(10, 421, 99, 49);
			iSetColor(200,0,100);
			iText(15, 440, scores, GLUT_BITMAP_HELVETICA_18);


			iSetColor(100,50,200);
			iText(10, 370, "ARROWS", GLUT_BITMAP_HELVETICA_18);
			iRectangle(10, 300, 100, 50);
			iSetColor(0,0,0);
			iFilledRectangle(10, 301, 99, 49);
			iSetColor(100,50,200);
			iText(15, 320, arrowss, GLUT_BITMAP_HELVETICA_18);

			iSetColor(200,0,100);
			iText(160, 480, "LEVEL", GLUT_BITMAP_HELVETICA_18);
			iRectangle(160, 420, 100, 50);
			iSetColor(0,0,0);
			iFilledRectangle(160, 421, 99, 49);
			iSetColor(200,0,100);
			iText(165, 440, lvls, GLUT_BITMAP_HELVETICA_18);
			if(lvl>=4)
			{
			iSetColor(0,0,0);	
			iFilledRectangle(180, 50, 80, 40);
			iSetColor(20,0,200);
			iRectangle(180,50,100,50);
			iText(200, 70, speeds, GLUT_BITMAP_HELVETICA_18);
			}

			iShowBMP(180,525, "quit.bmp");

			iShowBMP(10,520, "back.bmp");
			if(pr==1)
			iShowBMP(130,525, "pause.bmp");
			else
			iShowBMP(130,525, "resume.bmp");
			iSetColor(255,130,80);
			iCircle(50, 50, 100);
			iSetColor(0,0,0);
			double xa[]={0, 0, 200};
			double ya[]={0, 200, 0};
			iFilledPolygon(xa, ya, 3);
			iSetColor(255,130,80);
			iLine(50, 50, 150, 50);
			iLine(50,50,50,150);

			iSetColor(50,20,250);
			iLine(i,j,k,l);
			iPoint(k, l,3);
			

			iSetColor(200,20,100);
			iFilledEllipse(x, y, 15, 30);
			iSetColor(10,200,200);
			iLine(x, y-30, x, y-45);

			iSetColor(100,20,200);
			iFilledEllipse(p, q, 20, 40);
			iSetColor(200,200,100);
			iLine(p, q-40, p, q-70);

			
			iSetColor(100,200,100);
			iFilledEllipse(a, b, 17, 34);
			iSetColor(200,20,100);
			iLine(a, b-34, a, b-68);

			iSetColor(255,0,10);
			iFilledEllipse(mbx, mby, 18.5, 37);
			iSetColor(200,20,100);
			iLine(mbx, mby-34, mbx, mby-68);
			iSetColor(0,0,0);
			iFilledCircle(mbx,mby,7);

			iSetColor(200,200,80);
			iFilledEllipse(blx, bly, 18, 36);
			iSetColor(200,20,100);
			iLine(blx, bly-34, blx, bly-68);




			if(std==1&&pr==1)
			{
				if(k>=x-15&&k<=x+15&&l>=y-30&&l<=y+30)
				{
					x=750;
					y=-200;
					score+=30;
					itoa(score,scores,10);
				}
				if(k>=p-20&&k<=p+20&&l>=q-40&&l<=q+40)
				{
					p=850;
					q=-300;
					score+=10;
					itoa(score,scores,10);
				}
				if(k>=a-17&&k<=a+17&&l>=b-34&&l<=b+34)
				{
					a=950;
					b=-100;
					score+=20;
					itoa(score,scores,10);
				}
				if(k>=mbx-18.5&&k<=mbx+18.5&&l>=mby-37&&l<=mby+37)
				{
					mbx=650;
					mby=-3000;
					score-=20;
					itoa(score,scores,10);
				}

				if(k>=blx-18&&k<=blx+18&&l>=bly-36&&l<=bly+36)
				{
					blx=650;
					bly=-300;
					score+=15;
					itoa(score,scores,10);
				}
			}
			}

			
		}
		else if(mode==2)
		{
		iSetColor(0,0,0);
		iFilledRectangle(0, 0, 1000, 800);
		iShowBMP(200,10, "HELP 2.bmp");
		iShowBMP(200,450, "back.bmp");
		}
		else if(mode==3)
		{
		iSetColor(0,0,0);
		iFilledRectangle(0, 0, 1000, 800);
		iShowBMP(200,450, "back.bmp");
		iShowBMP(300,350, "hi2.bmp");
		iSetColor(20,0,200);
		pt=fopen("hi.txt","r");
		fscanf(pt,"%s",hss);
		fclose(pt);
		iText(320, 370, hss, GLUT_BITMAP_HELVETICA_18);


		}
	
}


void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=350 && mx<=650 && my>=400 && my<=500)
		{
			if(mode==0)
			mode=1;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=350 && mx<=613 && my>=100 && my<=200)
		{
			if(mode==0)
			mode=2;
		
		}
		if(mode==2)
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=200 && mx<=300 && my>=450 && my<=500)
		{
			mode=0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=300 && mx<=700 && my>=250 && my<=350)
		{	if(mode==0)
			mode=3;
		
		}
		if(mode==3)
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=200 && mx<=300 && my>=450 && my<=500)
		{
			mode=0;
		}
		if(mode==1)
		{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=180 && mx<=210 && my>=525 && my<=555)
		{
			lvl=0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=10 && mx<=110 && my>=520 && my<=570)
		{
			if(pr==1)
			{
				mode=0;
				score=0;
				itoa(score,scores,10);
				lvl=1;
				itoa(lvl,lvls,10);
				arrows=10;
				itoa(arrows,arrowss,10);
			}
			else
				mode=0;
		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=130 && mx<=160 && my>=525 && my<=555)
		{
			if(pr==1)
			{
			iPauseTimer(0);
			pr=pr*(-1);
			}
			else
			{
			iResumeTimer(0);
			pr=pr*(-1);
			}
		}
		if(lvl==0)
		{
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=700 && mx<=900 && my>=230 && my<=280)
			{
				lvl=1;
				itoa(lvl,lvls,10);
				score=0;
				itoa(score,scores,10);
				arrows=10;
				itoa(arrows,arrowss,10);
				mode=0;
				prev=0;
			}
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=735 && mx<=855 && my>=170 && my<=220)
			{
				lvl=1;
				itoa(lvl,lvls,10);
				score=0;
				itoa(score,scores,10);
				arrows=10;
				itoa(arrows,arrowss,10);
				mode=1;
				prev=0;
			}
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&& mx>=745 && mx<=845 && my>=110 && my<=160)
				exit(0);

		}

		}
}


void iKeyboard(unsigned char key)
{

}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP)
	{
		if(mode==1&&std==0&&pr==1)
		{
			if(k>=50)
			{
			k-=5;
			l=sqrt(20000-pow((k-50),2))+50;
			}


		}
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(mode==1&&std==0&&pr==1)
		{
			speed++;
			itoa(speed,speeds,10);

		}
	}
	if(key == GLUT_KEY_DOWN)
	{
		if(mode==1&&std==0&&pr==1)
		{
			if(l>=50)
			{
			l-=5;
			k=sqrt(20000-pow((l-50),2))+50;
			}

		}
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(std==0&&pr==1)
		{
			arrows=arrows-1;
			ok++;
			itoa(arrows,arrowss,10);
			std=1;
			m=((l-j)/(k-i));
			c=j-(m*i);
			co=(((l-j)*(l-j))+((k-i)*(k-i)))/((k-i)*(k-i));
		}
	}
}
void b1()
{
	if(lvl==1)
	{
	y=y+1;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+2;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+1.5;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+2;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+1.8;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}

	else if(lvl==2)
	{
	if(arrows==0&&ok==0)
	{
		arrows=10;
		itoa(arrows,arrowss,10);
	}

	y=y+2;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+4;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+3;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+4;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+3.6;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}
else if(lvl==2)
	{
	if(arrows==0&&ok==0)
	{
		arrows=10;
		itoa(arrows,arrowss,10);
	}

	y=y+2;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+4;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+3;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+4;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+3.6;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}

	else if(lvl==3)
	{
	if(arrows==0&&ok==0)
	{
		arrows=10;
		itoa(arrows,arrowss,10);
	}
		y=y+2;
	if(y<=200)
	x=x+.3;
	else if(y<=400)
	x=x-.3;
	else if(y<650)
	x=x+.3;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+4;
	if(q<=200)
	p=p+.5;
	else if(q<=400)
	p=p-.5;
	else if(q<650)
	p=p+.5;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+3;
	if(b<=200)
	a=a+.4;
	else if(b<=400)
	a=a-.4;
	else if(b<650)
	a=a+.4;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+4;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+3.6;
	if(bly<=200)
	blx=blx+.4;
	else if(bly<=400)
	blx=blx-.4;
	else if(bly<650)
	blx=blx+.4;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}

	else if(lvl==4)
	{
	if(arrows==0&&ok==0)
	{
		arrows=10;
		itoa(arrows,arrowss,10);
	}
	y=y+1;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+2;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+1.5;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+2;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+1.8;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}

	else if(lvl==5)
	{
	if(arrows==0&&ok==0)
	{
		arrows=10;
		itoa(arrows,arrowss,10);
	}

	y=y+2;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+4;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+3;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+4;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+3.6;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}

	else if(lvl==6)
	{
	if(arrows==0&&ok==0)
	{
		arrows=10;
		itoa(arrows,arrowss,10);
	}
		y=y+2;
	if(y<=200)
	x=x+.3;
	else if(y<=400)
	x=x-.3;
	else if(y<650)
	x=x+.3;
	if(y>=650)
	{
		y=-300;
		x=800;
	}
	q=q+4;
	if(q<=200)
	p=p+.5;
	else if(q<=400)
	p=p-.5;
	else if(q<650)
	p=p+.5;
	if(q>=650)
	{
		q=-200;
		p=650;
	}
	b=b+3;
	if(b<=200)
	a=a+.4;
	else if(b<=400)
	a=a-.4;
	else if(b<650)
	a=a+.4;
	if(b>=650)
	{
		b=-150;
		a=900;
	}
	mby=mby+4;
	if(mby>=650)
	{
		mby=-1550;
		mbx=600;
	}
	bly=bly+3.6;
	if(bly<=200)
	blx=blx+.4;
	else if(bly<=400)
	blx=blx-.4;
	else if(bly<650)
	blx=blx+.4;
	if(bly>=650)
	{
		bly=-400;
		blx=800;
	}
	}



}
void arrow()
{
	if(lvl>=4)
	{
		if(std==1&&pr==1)
			{
				i=i+(speed*(sqrt(co)));
				j=((m*i)-((i*i*.25)/(2*speed*speed*co)));
				k=k+(speed*(sqrt(co)));
				l=((m*k)-((k*k*.25)/(2*speed*speed*co)));
				if(i>=1000||j<=0)
				{
					speed=0;
					itoa(speed,speeds,10);
					if(arrows==0)
					{
						if(lvl!=0)
						{
						if(score-prev>=50)
						{
							lvl=lvl+1;
							ok=0;
							prev=score;
							itoa(lvl,lvls,10);
						}
						else
						{
							lvl=0;
						}
						}
					}
					else
					{
					std=0;
					i=50;
					j=50;
					k=150;
					l=150;
					}
				}
			}
	}
	else
	{
	if(std==1&&pr==1)
			{
				i=i+15;
				j=(m*i)+c;
				k=k+15;
				l=(m*k)+c;
				if(i>=1000||j>=600||j<=0)
				{
					if(arrows==0)
					{
						if(lvl!=0)
						{
						if(score-prev>=50)
						{
							lvl=lvl+1;
							ok=0;
							prev=score;
							itoa(lvl,lvls,10);
						}
						else
						{
							lvl=0;
						}
						}
					}
					else
					{
					std=0;
					i=50;
					j=50;
					k=150;
					l=150;
					}
				}
			}
	}
}

int main()
{
	iSetTimer(5,b1);
	iSetTimer(1,arrow);
	iInitialize(1000, 600, "Skyfall Savior");
	return 0;
}	