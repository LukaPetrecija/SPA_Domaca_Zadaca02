#include "game_of_life.h"
#include <ctime>
using namespace std;

bool game_of_life::slucajna_vrijednost()
{
    int slucajno = rand() % 4 + 1;
    if (slucajno == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}



game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

void game_of_life::sljedeca_generacija()
{
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            int broj_susjeda = 0;
            int yOs[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int xOs[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
            for (int k = 0; k < 8; k++)
            {
                int redak = (i + yOs[k] + REDAKA) % REDAKA;
                int stupac = (j + xOs[k] + STUPACA) % STUPACA;
                broj_susjeda += _generacija[redak][stupac];
            }
            if (_generacija[i][j])
            {
                if (broj_susjeda == 2 || broj_susjeda == 3)
                {
                    _sljedeca_generacija[i][j] = true;
                }
                else
                {
                    _sljedeca_generacija[i][j] = false;
                }
            }
            else
            {
                if (broj_susjeda == 3)
                {
                    _sljedeca_generacija[i][j] = true;
                }
                else
                {
                    _sljedeca_generacija[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::iscrtaj()
{
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            if (_generacija[i][j])
            {
                cout << '*';
            }
            else
            {
                cout << '-';
            }
        }
        cout << endl;
    }
    cout << endl;
}
