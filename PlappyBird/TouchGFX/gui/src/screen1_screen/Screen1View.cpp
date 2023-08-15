#include <gui/screen1_screen/Screen1View.hpp>
#include <cmsis_os.h>
Screen1View::Screen1View()
{
	tickCount = 0;
	t=0;
	c = 0;
	statue=1;
	v=0;
	start=0;
	tmp=0;
	score = 0;
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
extern osMessageQueueId_t Queue1Handle;
void Screen1View::handleTickEvent()
{
	Screen1ViewBase::handleTickEvent();
	if(start==0){
		uint8_t res=0;
			uint32_t count = osMessageQueueGetCount(Queue1Handle);
			if(count>0)
			{
				osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
				if(res == 'R')
					{
					v=2;
					start=1;
					}
			}
	}
	if(statue!=0 and start!=0){
	c -= statue;
	if(c%4==0)v-=1;
	tickCount=image10.getY()-v;
	image10.setY(tickCount);
	image8.setX((image8.getX()-2));
	image9.setX((image9.getX()-2));
	if(image8.getX() == -40) {
		image8.setX(320);
		image9.setX(320);
	}
	image11.setX((image11.getX()-2));
	image12.setX((image12.getX()-2));
	if(image11.getX() == -40) {
			image11.setX(320);
			image12.setX(320);
		}
	uint8_t res=0;
	uint32_t count = osMessageQueueGetCount(Queue1Handle);
	if(count>0)
	{
		osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
		if(res == 'R')
			{
			v=2;
			}
	}
	switch (c % 49)
	{
	case 42:
		image1.setVisible(true);
		image2.setVisible(false);
		image3.setVisible(false);
		image4.setVisible(false);
		image5.setVisible(false);
		image6.setVisible(false);
		image7.setVisible(false);
		break;
	case 35:
		image1.setVisible(false);
				image2.setVisible(true);
				image3.setVisible(false);
				image4.setVisible(false);
				image5.setVisible(false);
				image6.setVisible(false);
				image7.setVisible(false);
			break;
	case 28:
		image1.setVisible(false);
						image2.setVisible(false);
						image3.setVisible(true);
						image4.setVisible(false);
						image5.setVisible(false);
						image6.setVisible(false);
						image7.setVisible(false);
			break;
	case 21:
		image1.setVisible(false);
								image2.setVisible(false);
								image3.setVisible(false);
								image4.setVisible(true);
								image5.setVisible(false);
								image6.setVisible(false);
								image7.setVisible(false);
			break;
	case 14:
		image1.setVisible(false);
								image2.setVisible(false);
								image3.setVisible(false);
								image4.setVisible(false);
								image5.setVisible(true);
								image6.setVisible(false);
								image7.setVisible(false);
			break;
	case 7:
			image1.setVisible(false);
									image2.setVisible(false);
									image3.setVisible(false);
									image4.setVisible(false);
									image5.setVisible(false);
									image6.setVisible(true);
									image7.setVisible(false);
				break;
	case 0:
				image1.setVisible(false);
										image2.setVisible(false);
										image3.setVisible(false);
										image4.setVisible(false);
										image5.setVisible(false);
										image6.setVisible(false);
										image7.setVisible(true);
					break;
	}
	uint32_t bird[4];
	uint32_t pipe[4][4];
	bird[0]=image10.getX();
	bird[1]=image10.getY();
	bird[2]=image10.getWidth();
	bird[3]=image10.getHeight();
	if(image10.getY()>=288) statue=0;
	pipe[1][1]=image8.getY();
	pipe[0][0]=image9.getX();
	pipe[0][1]=image9.getY();
	pipe[0][2]=image9.getWidth();
	pipe[0][3]=image9.getHeight();
	if (bird[0]+bird[2]>=pipe[0][0] and bird[0]<=pipe[0][0]+pipe[0][2] and (bird[1]<=pipe[0][1]+pipe[0][3] or bird[1]+bird[3] >= pipe[1][1])) statue = 0;
	pipe[3][1]=image11.getY();
	pipe[2][0]=image12.getX();
	pipe[2][1]=image12.getY();
	pipe[2][2]=image12.getWidth();
	pipe[2][3]=image12.getHeight();
	if (bird[0]+bird[2]>=pipe[2][0] and bird[0]<=pipe[2][0]+pipe[2][2] and (bird[1]<=pipe[2][1]+pipe[2][3] or bird[1]+bird[3] >= pipe[3][1])) statue = 0;
	if(pipe[0][0] == 290){
			tmp=bird[1]%3*50-50;
			image8.setY(205+tmp);
			image9.setY(-165+tmp);
		}
	if(pipe[2][0] == 290){
				tmp=bird[1]%3*50-50;
				image11.setY(205+tmp);
				image12.setY(-165+tmp);
		}
	if((bird[0]==pipe[0][0]+pipe[0][2] or bird[0]==pipe[2][0]+pipe[2][2]) and statue == 1) score ++;
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d",score);
	invalidate();
	}
}
