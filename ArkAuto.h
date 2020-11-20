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

	//EventCheck OF4Start;

	int StartCheck1;
	int StartCheck2;
	int FinishCheck1;
	int FinishCheck2;

	int OF4StartCheck;

	bool matchPointCheck(EventCheck ev, int scanBGR, int devi)
	{
		return (ev.B >= (scanBGR >> 16) - devi && ev.B <= (scanBGR >> 16) + devi)
			&& (ev.G >= (scanBGR >> 8 & 0xff) - devi && ev.G <= (scanBGR >> 8 & 0xff) + devi)
			&& (ev.R >= (scanBGR & 0xff) - devi && ev.R <= (scanBGR & 0xff) + devi);
	}
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

	Start1 = {1577, 924, 13931008, 13931008 >> 16, 13931008 >> 8 & 0xff, 13931008 & 0xff};
	Start2 = {1508, 910, 18113, 18113 >> 16, 18113 >> 8 & 0xff, 18113 & 0xff};
	Finish1 = {1410, 712, 169727, 169727 >> 16, 169727 >> 8 & 0xff, 169727 & 0xff};
	Finish2 = {524, 921, 16777215, 16777215 >> 16, 16777215 >> 8 & 0xff, 16777215 & 0xff};

	/* Event only */
	//OF4Start = {1622, 922, 11826125, 117, 112, 201};
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

		//OF4StartCheck = GetPixel(DC, OF4Start.X, OF4Start.Y);

		if (matchPointCheck(Start1, StartCheck1, 5))
		{
			MouseClick(Start1.X, Start1.Y);
		}
		else if (matchPointCheck(Start2, StartCheck2, 5))
		{
			MouseClick(Start2.X, Start2.Y);
		}
		else if(matchPointCheck(Finish1, FinishCheck1, 5) && matchPointCheck(Finish2, FinishCheck2, 5))
		{
			MouseClick(Finish1.X, Finish1.Y);
		}
		/*
		else if(OF4StartCheck == OF4Start.BGR)
		{
			MouseClick(OF4Start.X, OF4Start.Y);
		}*/
		Sleep(2000);
	}	
}
