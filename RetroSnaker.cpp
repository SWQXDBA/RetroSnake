#define _CRT_SECURE_NO_WARNINGS

#include"RetroSnaker.h"
using namespace std;
int menu() {

    settextcolor(LIGHTGREEN);
    setbkmode(TRANSPARENT);
    settextstyle(25, 0, "����");
//flag:
    BeginBatchDraw();
    IMAGE img;
    loadimage(&img, "./����.jpg", 0, 0);
    putimage(0, 0, &img);
    /*outtextxy(LENGTH / 2-70, WIDTH / 2 - 100, "1.��ʼ��Ϸ");
    outtextxy(LENGTH / 2-70, WIDTH / 2 -50, "0.�˳���Ϸ");*/
    outtextxy(LENGTH / 2 - 90, WIDTH / 2 - 100, "��ӭ����̰����С��Ϸ");
    outtextxy(LENGTH / 2 - 70, WIDTH / 2 - 50, "���������ʼ��Ϸ");
    EndBatchDraw();
    /*outtextxy(LENGTH / 2-100, WIDTH / 2 -50, "3.��Ϸ���");*/
    _getch();
    return 1;
    //switch (_getch())
    //{
    //case '1':
    //	return 1;
    //case '0':
    //	return 0;
    //	default:
    //	//BeginBatchDraw();
    //	cleardevice();
    //	putimage(0, 0, &img);
    //	outtextxy(LENGTH / 2 - 200, WIDTH / 2 - 100, "�����������������룡");
    //	Sleep(1000);
    //	cleardevice();
    //	//EndBatchDraw();
    //	goto flag;
    //}
}

void Init(Snaker* snaker , Food* food)
{
    //��������
    mciSendString("open ./bgm.mp3 alias BGM", 0, 0, 0);
    mciSendString("play BGM repeat", 0, 0, 0);
    snaker->grade = 0;//��ʼ����Ϊ0
    snaker->size = 5;//��ʼ����Ϊ5
    snaker->dir = RIGHT;//��ʼ����
    snaker->speed = 10;//Ĭ���ٶ�Ϊ10
    snaker->flag = 1;//Ĭ�ϴ��
    //snaker->speed = 10;
    //snaker->r = 5;Բ���߰뾶
    snaker->a = 10;//�����߱߳�
    snaker->s = 70;//ˢ��Ƶ��
    for (int i = 0; i < snaker->size; i++) {
        snaker->coor[i].x = LENGTH / 2 - i * 10;
        //snaker->coor[i].x = LENGTH / 2 - i * 10;
        snaker->coor[i].y = WIDTH / 2;
    }
    //������
    food->coor.x = rand() % (LENGTH / 10-4) * 10+20;//ʳ��λ�����
    food->coor.y = rand() % (WIDTH / 10-4) * 10+20;
    /*food->coor.x = rand() % LENGTH;
    food->coor.y = rand() % WIDTH;*///Բ����
    food->color = RGB(rand() % 256, rand() % 256, rand() % 256);//ʳ����ɫ���
    //snaker->color = food->color;//��ʼ���ߵ���ɫ
    food->flag = 1;//ʳ�����
    //food->r = 5;//Բ��ʳ��
    food->a = 10;//����ʳ��
}
void ShowSidebar(Snaker* snaker)//�����
{
    setlinecolor(WHITE);
    line(LENGTH,0 ,LENGTH,WIDTH);
    char grade[20];
    /*char speed[20];
    char grade[20];*/
    sprintf(grade, "�÷֣�%d", snaker->grade);
    settextcolor(LIGHTGREEN);
    settextstyle(25, 0, "����");
    outtextxy(LENGTH + 30, 50, grade);
    outtextxy(LENGTH + 30, 50, grade);
    outtextxy(LENGTH + 30, 50, grade);
    outtextxy(LENGTH + 30, 90, "��Esc����ͣ");
    outtextxy(LENGTH + 30, 130, "W����");
    outtextxy(LENGTH + 30, 170, "S����");
    outtextxy(LENGTH + 30, 210, "A����");
    outtextxy(LENGTH + 30, 250, "D����");
    outtextxy(LENGTH + 30, 290, "�ո����");
    outtextxy(LENGTH + 30, 330, "L������");
}
void GameDraw(Snaker* snaker, Food* food)//������
{

    //�������ƻ�ͼ������

    cleardevice();//����
    /*IMAGE img;
    loadimage(&img, "����.jpg", 0, 0);
    putimage(0, 0, &img);*/
    setbkcolor(RGB(91, 97, 105));//���ñ�  ������ɫ
    //etfillcolor(RGB(rand()%256, rand() % 256, rand() % 256));//�����ߵ���ɫGREEN
    for (int i = 0; i < snaker->size; i++) {
        //setfillcolor(RGB(rand()%256, rand() % 256, rand() % 256));//�����ߵ���ɫ���
        setfillcolor(HSVtoRGB(7.0*i,0.9,1.0));//�����ߵ���ɫ����
        //�ޱ߿���
        /*solidrectangle(snaker->coor[i].x, snaker->coor[i].y,
            snaker->coor[i].x + 10, snaker->coor[i].y + 10);*/
        //�б߿���
        fillrectangle(snaker->coor[i].x, snaker->coor[i].y,
                      snaker->coor[i].x + snaker->a, snaker->coor[i].y + snaker->a);

    }

    ShowSidebar(snaker);//��ӡ�����

    setfillcolor(food->color);//����ʳ�����ɫ
     fillrectangle(food->coor.x, food->coor.y, food->coor.x + food->a, food->coor.y + food->a);
     FlushBatchDraw();
  //  EndBatchDraw();//˫������������ͼ��


}
//void GameDraw(Snaker* snaker,Food* food) //Բ����
//{
//	//˫�����ͼ������
//	BeginBatchDraw();//˫���忪ʼ
//	setbkcolor(RGB(91, 97, 105));//���ñ�����ɫ
//	cleardevice();//����
//	//etfillcolor(RGB(rand()%256, rand() % 256, rand() % 256));//�����ߵ���ɫGREEN
//	setfillcolor(GREEN);//�����ߵ���ɫ
//	//������
//	//solidcircle(snaker->coor[0].x, snaker->coor[0].y, snaker->r *2);
//	/*for (int i = 1; i < snaker->size; i++) {
//		solidcircle(snaker->coor[i].x, snaker->coor[i].y, snaker->r);
//	}*/
//	for (int i = 0; i < snaker->size; i++) {
//		solidcircle(snaker->coor[i].x, snaker->coor[i].y, snaker->r);
//	}
//	//����ʳ��
//  setfillcolor(food->color);//����ʳ�����ɫ
//	solidcircle(food->coor.x, food->coor.y, food->r);//Բ��ʳ��
//	EndBatchDraw();//˫�������
//}
//
void SnakerMove(Snaker* snaker)//���ܴ�ǽ
{
    int i = 0;
    for (i = snaker->size - 1; i > 0; i--) {
        snaker->coor[i] = snaker->coor[i - 1];
    }
    switch (snaker->dir) {
        case UP:
            snaker->coor[0].y -= snaker->speed;
            break;
        case DOWN:
            snaker->coor[0].y += snaker->speed;
            break;
        case LEFT:
            snaker->coor[0].x -= snaker->speed;
            break;
        case RIGHT:
            snaker->coor[0].x += snaker->speed;
            break;
        default:
            break;
    }
}
//void SnakerMove(Snaker* snaker)//��ǽ
//{
//	int i = 0;
//	for (i = snaker->size - 1; i > 0; i--) {
//		snaker->coor[i] = snaker->coor[i - 1];
//	}
//
//	switch (snaker->dir) {
//	case UP:
//		snaker->coor[0].y -= snaker->speed;
//		if (snaker->coor[0].y <= 0) {
//			snaker->coor[0].y = WIDTH;
//		}
//		break;
//	case DOWN:
//		snaker->coor[0].y += snaker->speed;
//		if (snaker->coor[0].y >= WIDTH) {
//			snaker->coor[0].y = 0;
//		}
//		break;
//	case LEFT:
//		snaker->coor[0].x -= snaker->speed;
//		if (snaker->coor[0].x <= 0) {
//			snaker->coor[0].x = LENGTH;
//		}
//		break;
//	case RIGHT:
//		snaker->coor[0].x += snaker->speed;
//		if (snaker->coor[0].x >= LENGTH) {
//			snaker->coor[0].x = 0;
//		}
//		break;
//	default:
//		break;
//	}
//}
//Բ����
//void SnakerMove(Snaker* snaker)
//{
//	int i = 0;
//	for (i = snaker->size-1; i > 0 ; i--) {
//		snaker->coor[i] = snaker -> coor[i -1];
//	}
//
//	switch (snaker->dir) {
//			case UP:
//				snaker->coor[0].y-=snaker->speed;
//				if (snaker->coor[0].y  <= 0) {
//					snaker->coor[0].y = WIDTH;
//				}
//				break;
//			case DOWN:
//				snaker->coor[0].y+= snaker->speed;
//				if (snaker->coor[0].y  >= WIDTH) {
//					snaker->coor[0].y = 0;
//				}
//				break;
//			case LEFT:
//				snaker->coor[0].x-= snaker->speed;
//				if (snaker->coor[0].x <= 0) {
//					snaker->coor[0].x = LENGTH;
//				}
//				break;
//			case RIGHT:
//				snaker->coor[0].x+= snaker->speed;
//				if (snaker->coor[0].x  >= LENGTH) {
//					snaker->coor[0].x = 0;
//				}
//				break;
//			default:
//				break;
//	}
//}

void Keyboard(Snaker* snaker)
{
    //�������Ƿ�������
    if (_kbhit()) {
        //��ȡһ���ַ�
        switch (_getch()) {
            case 'w':
            case 'W':
            case 72://��ֵ
                if (snaker->dir != DOWN) {
                    snaker->dir = UP;
                }
                break;
            case 's':
            case 'S':
            case 80:
                if (snaker->dir != UP) {
                    snaker->dir = DOWN;
                }
                break;
            case 'a':
            case 'A':
            case 75:
                if (snaker->dir != RIGHT) {
                    snaker->dir = LEFT;
                }
                break;
            case 'd':
            case 'D':
            case 77:
                if (snaker->dir != LEFT) {
                    snaker->dir = RIGHT;
                }
                break;
            case ' ':
                if (snaker->s) {
                    snaker->s -= 10;
                }
                break;
            case 'l':
            case 'L':
                if (snaker->s < 150) {
                    snaker->s += 10;
                }
                break;
            case 27:Esc();
                break;
            default:
                break;
        }
    }
}

void EatFood(Snaker* snaker, Food* food)
{
    //������
    if (snaker->coor[0].x == food->coor.x && snaker->coor[0].y == food->coor.y) {
       snaker->size++;
        food->flag = 0;
        if (snaker->s >= 80) {
            snaker->grade++;
        }
        else {
            snaker->grade+=(80-snaker->s)/3;
        }
        while (!food->flag) {//ʳ�ﲻ����ˢ��ʳ��
            food->coor.x = rand() % (LENGTH / 10) * 10;
            food->coor.y = rand() % (WIDTH /10 ) *10;
            food->flag = 1;//ˢ��ʳ��
            for (int i = 0; i < snaker->size; i++) {
                if (food->coor.x == snaker->coor[i].x && food->coor.y == snaker->coor[i].y) {
                    food->flag = 0;//ʳ�������������ˢ��ʳ��
                }
            }
        }
        food->color = RGB(rand() % 256, rand() % 256, rand() % 256);//ʳ����ɫ���
        //cleardevice();//����
    }
    //Բ����
    //if (snaker->coor[0].x >= food->coor.x - food->r
    //	&& snaker->coor[0].x <= food->coor.x + food->r
    //	&& snaker->coor[0].y >= food->coor.y - food->r
    //	&& snaker->coor[0].y <= food->coor.y + food->r) {
    //	snaker->size++;
    //	food->coor.x = rand() % (LENGTH / 10 - 4) * 10 + 20;
    //	food->coor.y = rand() % (WIDTH /10 - 4)*10 + 20;
    //	snaker->color = food->color;//�����ߵ���ɫ�ͳԵ���ʳ��һ��
    //	food->color = rand() % 256;
    //	//food->flag = 0;
    //}
    //if (snaker->coor[0].x + snaker->r >= food->coor.x - food->r
    //	&& snaker->coor[0].x - snaker->r <= food->coor.x + food->r
    //	&& snaker->coor[0].y + snaker->r >= food->coor.y - food->r
    //	&& snaker->coor[0].y - snaker->r <= food->coor.y + food->r) {
    //	snaker->size++;
    //	//food->flag = 0;
    //	food->coor.x = rand() % (LENGTH /10 - 4)*10+ 20;
    //	food->coor.y = rand() % (WIDTH /10 - 4)*10 + 20;
    //
    //}
}
void Esc()
{
    //Esc��ֵ27
    outtextxy(LENGTH / 2 - 100, WIDTH / 2 - 100, "�ٴε��Esc�˳���Ϸ");
    outtextxy(LENGTH / 2 - 100, WIDTH / 2 - 50, "�����������");
    switch (_getch()) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}
void SnakerDie(Snaker* snaker, Food* food) {
    if (snaker->coor[0].x >= LENGTH || snaker->coor[0].x < 0 ||
        snaker->coor[0].y >= WIDTH || snaker->coor[0].y < 0) {
        settextcolor(LIGHTGREEN);
        settextstyle(80, 0, _T("����"));
        setbkmode(TRANSPARENT);
        outtextxy(240, 220, _T("��Ϸ����"));
        //char grade[20];
        /*sprintf(grade, "�ܵ÷֣�%d", snaker->grade);
        settextcolor(LIGHTGREEN);
        settextstyle(25, 0, "����");
        outtextxy(240, 240, grade)*/;
        snaker->flag = 0;
        mciSendString(TEXT("close BGM"), 0, 0, 0);
        return;
    }
    for (int i = 1; i < snaker->size; i++) {
        if (snaker->coor[0].x == snaker->coor[i].x && snaker->coor[0].y == snaker->coor[i].y) {
            settextcolor(LIGHTGREEN);
            settextstyle(60, 0, _T("����"));
            setbkmode(TRANSPARENT);
            outtextxy(100, 100, _T("��Ϸ����"));
            //char grade[20];
            /*sprintf(grade, "�ܵ÷֣�%d", snaker->grade);
            settextcolor(LIGHTGREEN);
            settextstyle(25, 0, "����");
            outtextxy(240, 240, grade)*/;
            snaker->flag = 0;
            mciSendString(TEXT("close BGM"), 0, 0, 0);
            return;
        }
    }
}