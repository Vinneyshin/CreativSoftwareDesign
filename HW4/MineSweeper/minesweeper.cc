#include "minesweeper.h"

Minesweeper::Minesweeper()
{
}

Minesweeper::~Minesweeper()
{
}

bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map)
{
	m_map.assign(_map.begin(), _map.end()); 
	m_width = (int)(_width - '0');
	m_height = (int)(_height - '0');

	int a[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int b[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 8; k++)
				if (m_height > i + a[k]
					&& i + a[k]  >= 0 
					&& m_width > j + b[k]
					&& j + b[k] >= 0 
					&& m_map[i + a[k]][j + b[k]] == '*') cnt++;
			if (m_map[i][j] != '*') m_map[i][j] = cnt + '0';
			cout << m_map[i][j];
		}
		cout << endl;
	}
	return true;
}

bool Minesweeper::toggleMine(int _x, int _y)
{
	int tmp_height = _y - '0';
	int tmp_width = _x - '0';
	
	if (m_map[tmp_height][tmp_width] == '*') m_map[tmp_height][tmp_width] = '0';
	else m_map[tmp_height][tmp_width] = '*';
	
	

	int a[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int b[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 8; k++)
				if (m_height > i + a[k]
					&& i + a[k] >= 0
					&& m_width > j + b[k]
					&& j + b[k] >= 0
					&& m_map[i + a[k]][j + b[k]] == '*') cnt++;
			if (m_map[i][j] != '*') m_map[i][j] = cnt + '0';
			cout << m_map[i][j];
		}
		cout << endl;
	}

	return true;
}

size_t Minesweeper::width() const
{
	return m_width;
}

size_t Minesweeper::height() const
{
	return m_height;
}

char Minesweeper::get(int _x, int _y) const
{
	return 0;
}

bool Minesweeper::setPlay()
{
	m_touchcount = 0;
	m_playmap.assign(m_map.begin(), m_map.end());
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++)
		{
			m_playmap[i][j] = '_';
			cout << m_playmap[i][j];
		}
		cout << endl;
	}
	return true;
}

bool Minesweeper::touchMap(int _x, int _y)
{
	int tmp_height = _y - '0';
	int tmp_width = _x - '0';
	
	m_touchcount++;

	if (m_map[tmp_height][tmp_width] == '*')
		cout << "DEAD(" << m_touchcount << ")" << endl;
	else
	{
		m_playmap[tmp_height][tmp_width] = m_map[tmp_height][tmp_width];
		for (int i = 0; i < m_height; i++) {
			for (int j = 0; j < m_width; j++)
			{
				cout << m_playmap[i][j];
			}
			cout << endl;
		}
	}
	
	return true;
}

int Minesweeper::touchCount() const
{
	return m_touchcount;
}
