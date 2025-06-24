#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int winA = 0, draw = 0, loseA = 0;
    int aWinB = 0, aWinC = 0, aWinJ = 0;
    int bWinB = 0, bWinC = 0, bWinJ = 0;

    for (int i = 0; i < N; i++)
    {
        char a, b;
        cin >> a >> b;
        if (a == b)
            draw++;
        else if ((a == 'C' && b == 'J') ||
            (a == 'J' && b == 'B') ||
            (a == 'B' && b == 'C'))
        {
            winA++;
            if (a == 'B') aWinB++;
            else if (a == 'C') aWinC++;
            else if (a == 'J') aWinJ++;
        }
        else
        {
            loseA++;
            if (b == 'B') bWinB++;
            else if (b == 'C') bWinC++;
            else if (b == 'J') bWinJ++;
        }
    }
    cout << winA << " " << draw << " " << loseA << endl;
    cout << loseA << " " << draw << " " << winA << endl;
    char maxAGesture;
    if (aWinB >= aWinC && aWinB >= aWinJ) maxAGesture = 'B';
    else if (aWinC >= aWinJ) maxAGesture = 'C';
    else maxAGesture = 'J';
    char maxBGesture;
    if (bWinB >= bWinC && bWinB >= bWinJ) maxBGesture = 'B';
    else if (bWinC >= bWinJ) maxBGesture = 'C';
    else maxBGesture = 'J';
    cout << maxAGesture << " " << maxBGesture << endl;

    return 0;
}