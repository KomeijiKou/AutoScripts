#pragma once
class ArkAuto
{
public:
	bool loopCon;

	ArkAuto();
	~ArkAuto();
	
	void StartArkAuto();
private:
	struct EventCheck {
		int X;
		int Y;
		int BGR;
		int B;
		int G;
		int R;
	};

	HDC DC;

	EventCheck Start1;
	EventCheck Start2;
	EventCheck Finish1;
	EventCheck Finish2;

	int StartCheck1;
	int StartCheck2;
	int FinishCheck1;
	int FinishCheck2;

	void MouseClick(int x, int y)
	{
		SetCursorPos(x, y);
		Sleep(20);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(30);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
};

ArkAuto::ArkAuto()
{
	/*BGR >> 16, BGR >> 8 & 0xff, BGR & 0xff*/
	loopCon = false;
	DC = GetDC(0);

	Start1.X = 1577;
	Start1.Y = 924;
	Start1.BGR = 13931008;
	Start1.B = Start1.BGR >> 16;
	Start1.G = Start1.BGR >> 8 & 0xff;
	Start1.R = Start1.BGR & 0xff;

	Start2.X = 1508;
	Start2.Y = 910;
	Start2.BGR = 18113;
	Start2.B = Start2.BGR >> 16;
	Start2.G = Start2.BGR >> 8 & 0xff;
	Start2.R = Start2.BGR & 0xff;

	Finish1.X = 1410;
	Finish1.Y = 712;
	Finish1.BGR = 169727;
	Finish1.B = Finish1.BGR >> 16;
	Finish1.G = Finish1.BGR >> 8 & 0xff;
	Finish1.R = Finish1.BGR & 0xff;

	Finish2.X = 524;
	Finish2.Y = 921;
	Finish2.BGR = 16777215;
	Finish2.B = Finish2.BGR >> 16;
	Finish2.G = Finish2.BGR >> 8 & 0xff;
	Finish2.R = Finish2.BGR & 0xff;
}

ArkAuto::~ArkAuto()
{
}

void ArkAuto::StartArkAuto()
{
	
	loopCon = true;
	while (loopCon)
	{
		StartCheck1 = GetPixel(DC, Start1.X, Start1.Y);
		StartCheck2 = GetPixel(DC, Start2.X, Start2.Y);
		FinishCheck1 = GetPixel(DC, Finish1.X, Finish1.Y);
		FinishCheck2 = GetPixel(DC, Finish2.X, Finish2.Y);

		if ((Start1.B >= (StartCheck1 >> 16) - 5 && Start1.B <= (StartCheck1 >> 16) + 5) && (Start1.G >= (StartCheck1 >> 8 & 0xff) - 5 && Start1.G <= (StartCheck1 >> 8 & 0xff) + 5) && (Start1.R >= (StartCheck1 & 0xff) - 5 && Start1.R <= (StartCheck1 & 0xff) + 5))
		{
			MouseClick(Start1.X, Start1.Y);
		}
		else if ((Start2.B >= (StartCheck2 >> 16) - 5 && Start2.B <= (StartCheck2 >> 16) + 5) && (Start2.G >= (StartCheck2 >> 8 & 0xff) - 5 && Start2.G <= (StartCheck2 >> 8 & 0xff) + 5) && (Start2.R >= (StartCheck2 & 0xff) - 5 && Start2.R <= (StartCheck2 & 0xff) + 5))
		{
			MouseClick(Start2.X, Start2.Y);
		}
		else if(((Finish1.B >= (FinishCheck1 >> 16) - 5 && Finish1.B <= (FinishCheck1 >> 16) + 5) && (Finish1.G >= (FinishCheck1 >> 8 & 0xff) - 5 && Finish1.G <= (FinishCheck1 >> 8 & 0xff) + 5) && (Finish1.R >= (FinishCheck1 & 0xff) - 5 && Finish1.R <= (FinishCheck1 & 0xff) + 5)) && FinishCheck2 >> 16 >= 250 && FinishCheck2 >> 8 & 0xff >= 250 && FinishCheck2 & 0xff >= 250)
		{
			MouseClick(Finish1.X, Finish1.Y);
		}
		Sleep(2000);
	}
}