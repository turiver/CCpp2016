#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
struct zb { float x; float y; int t; };
struct za
{
	float x;
	float y;
	bool k;
	bool h;
	int b;
};
zb shell[1100],eshell[2000];
za enemy[1100];
//enemy 130 73
//my  80 106
//shell 10 10
//game over 612 135
void drawmy();
void loadfile();
void drawlife();
void drawshell();
void draweshell();
void proshell();
void moveshell();
void moveeshell();
void movemy();
void proememy();
void moveenemy();
void drawenemy();
void checkshell();
void proeshell();
void vividboom(int i);
void boommy();
int shellnum,enemynum,losex,losey,eshellnum,blood,life,atktype,score;
bool lose,damage,crash;
bool in1, in2, in3, load1, load2, load3,inpass;
sf::Vector2f p;
sf::Clock cl,c,ce,ck[1100],ch[1100],shellc[1100],clocklose,ces[1100],dam,check,shift,c1,c2,c3;
sf::RenderWindow window(sf::VideoMode(800, 800), "GAME");
sf::Texture texture, pao, ty, b,go,es,back,ll1,ll2,ll3,ppa;
sf::Texture hhp,bblo,mmy,ppao2,llife,mini,ssc,scll;
sf::Sprite hp,blo,li,minimy,sco,scl,l1,l2,l3,pa;
sf::Sprite sprite, she, ene,boom,lo,e,ba,my,pao2;
sf::Texture b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19;
sf::Texture m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19;
sf::SoundBuffer bjyy,fss,boo,boo2;
sf::Sound bj,fs,ex,ex2;
int main()
{
	memset(eshell, 0, sizeof(eshell));
	loadfile();
	she.setTexture(pao);
	pao2.setTexture(ppao2);

	my.setTexture(mmy);

	ene.setTexture(ty);
	e.setTexture(es);
	ba.setTexture(back);
	boom.setTexture(b);
	hp.setTexture(hhp);
	blo.setTexture(bblo);
	li.setTexture(llife);
	minimy.setTexture(mini);
	sco.setTexture(ssc);
	scl.setTexture(scll);
	pa.setTexture(ppa);

	l1.setTexture(ll1);
	l2.setTexture(ll2);
	l3.setTexture(ll3);

	li.setPosition(sf::Vector2f(10, 750));
	my.setPosition(sf::Vector2f(355, 680));
	ba.setPosition(sf::Vector2f(-1000, -3200));
	hp.setPosition(sf::Vector2f(10, 10));
	blo.setPosition(sf::Vector2f(70, 20));
	sco.setPosition(sf::Vector2f(10, 50));
	scl.setPosition(sf::Vector2f(100, 55));
	l1.setPosition(sf::Vector2f(200, 300));
	l2.setPosition(sf::Vector2f(200, 300));
	l3.setPosition(sf::Vector2f(200, 300));
	pa.setPosition(sf::Vector2f(130, 270));


	shellnum = 0;
	enemynum = 0;
	eshellnum = 0;
	lose = 0;
	damage = 0;
	score = 0;
	blood = 10;
	life = 3;
	atktype = 1;

	in1 = 0;
	in2 = 0;
	in3 = 0;
	load1 = 1;
	load2 = 0;
	load3 = 0;
	inpass = 0;

	srand(time(0));
	sf::Time a;
	c1.restart();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (load1)
		{
			window.clear();
			window.draw(l1);
			window.display();
			if (c1.getElapsedTime() > sf::seconds(3))
			{
				load1 = 0;
				in1 = 1;
			}
			continue;
		}
		if (load2)
		{
			window.clear();
			window.draw(l2);
			window.display();
			if (c2.getElapsedTime() > sf::seconds(2))
			{
				load2 = 0;
				in2 = 1;
			}
			continue;
		}
		if (load3)
		{
			window.clear();
			window.draw(l3);
			window.display();
			if (c3.getElapsedTime() > sf::seconds(2))
			{
				load3 = 0;
				in3 = 1;
			}
			continue;
		}
		if (inpass)
		{
			window.clear();
			window.draw(pa);
			window.display();
			continue;
		}
		blo.setTextureRect(sf::IntRect(0, 0, blood * 30, 13));
		scl.setTextureRect(sf::IntRect(0, 0, score * 15, 13));
		if ((!lose)&&(!crash))
		{
			p = my.getPosition();
			movemy();
			checkshell();
			moveshell();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { proshell(); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&& (shift.getElapsedTime() > sf::seconds(0.5)))
			{
				if (atktype == 1) atktype = 2;
				else atktype = 1;
				shift.restart();
			}
			a = ce.getElapsedTime();
			if (a >= sf::seconds(1))
			{
				proememy();
				ce.restart();
			}
			proeshell();
			moveeshell();
			moveenemy();
		}
		if (score >= 12)
		{
			if (in1)
			{
				in1 = 0;
				load2 = 1;
				score = 0;
				shellnum = 0;
				enemynum = 0;
				eshellnum = 0;
				c2.restart();
			}
			if (in2)
			{
				in2 = 0;
				load3 = 1;
				score = 0;
				shellnum = 0;
				enemynum = 0;
				eshellnum = 0;
				c3.restart();
			}
			if (in3)
			{
				in3 = 0;
				inpass = 1;
			}
		}
		window.clear();
		if (lose)
		{
			if (clocklose.getElapsedTime() > sf::seconds(2))
			{
				lo.setTexture(go);
				lo.setPosition(sf::Vector2f(89, 300));
				window.draw(lo);
			}
			else
			{
				drawshell();
				draweshell();
				drawenemy();
				boommy();
			}
		}
		else
		{
			if (crash)
			{
				drawshell();
				draweshell();
				drawenemy();
				boommy();
				if (clocklose.getElapsedTime() >= sf::seconds(2))
				{
					my.setPosition(sf::Vector2f(355, 680));
					blood = 10;
					crash = 0;
					shellnum = 0;
					enemynum = 0;
					eshellnum = 0;
				}
			}
			else
			{
				window.draw(hp);
				window.draw(blo);
				window.draw(li);
				window.draw(sco);
				window.draw(scl);
				drawlife();
				drawmy();
				drawshell();
				draweshell();
				drawenemy();
			}
		}
		window.display();
	}

	return 0;
}
void loadfile()
{
	if (!mmy.loadFromFile("my.png")) { exit(-1); }
	if (!ppao2.loadFromFile("pao2.png")) { exit(-1); }
	if (!pao.loadFromFile("pao.png")) { exit(-1); }
	if (!ty.loadFromFile("enemy.png")) { exit(-1); }
	if (!es.loadFromFile("pao.png")) { exit(-1); }
	if (!b.loadFromFile("boom.png")) { exit(-1); }

	if (!b1.loadFromFile("b1.png")) { exit(-1); }
	if (!b2.loadFromFile("b2.png")) { exit(-1); }
	if (!b3.loadFromFile("b3.png")) { exit(-1); }
	if (!b4.loadFromFile("b4.png")) { exit(-1); }
	if (!b5.loadFromFile("b5.png")) { exit(-1); }
	if (!b6.loadFromFile("b6.png")) { exit(-1); }
	if (!b7.loadFromFile("b7.png")) { exit(-1); }
	if (!b8.loadFromFile("b8.png")) { exit(-1); }
	if (!b9.loadFromFile("b9.png")) { exit(-1); }
	if (!b10.loadFromFile("b10.png")) { exit(-1); }
	if (!b11.loadFromFile("b11.png")) { exit(-1); }
	if (!b12.loadFromFile("b12.png")) { exit(-1); }
	if (!b13.loadFromFile("b13.png")) { exit(-1); }
	if (!b14.loadFromFile("b14.png")) { exit(-1); }
	if (!b15.loadFromFile("b15.png")) { exit(-1); }
	if (!b16.loadFromFile("b16.png")) { exit(-1); }
	if (!b17.loadFromFile("b17.png")) { exit(-1); }
	if (!b18.loadFromFile("b18.png")) { exit(-1); }
	if (!b19.loadFromFile("b19.png")) { exit(-1); }

	if (!m1.loadFromFile("m1.png")) { exit(-1); }
	if (!m2.loadFromFile("m2.png")) { exit(-1); }
	if (!m3.loadFromFile("m3.png")) { exit(-1); }
	if (!m4.loadFromFile("m4.png")) { exit(-1); }
	if (!m5.loadFromFile("m5.png")) { exit(-1); }
	if (!m6.loadFromFile("m6.png")) { exit(-1); }
	if (!m7.loadFromFile("m7.png")) { exit(-1); }
	if (!m8.loadFromFile("m8.png")) { exit(-1); }
	if (!m9.loadFromFile("m9.png")) { exit(-1); }
	if (!m10.loadFromFile("m10.png")) { exit(-1); }
	if (!m11.loadFromFile("m11.png")) { exit(-1); }
	if (!m12.loadFromFile("m12.png")) { exit(-1); }
	if (!m13.loadFromFile("m13.png")) { exit(-1); }
	if (!m14.loadFromFile("m14.png")) { exit(-1); }
	if (!m15.loadFromFile("m15.png")) { exit(-1); }
	if (!m16.loadFromFile("m16.png")) { exit(-1); }
	if (!m17.loadFromFile("m17.png")) { exit(-1); }
	if (!m18.loadFromFile("m18.png")) { exit(-1); }
	if (!m19.loadFromFile("m19.png")) { exit(-1); }

	if (!go.loadFromFile("gameover.png")) { exit(-1); }
	if (!back.loadFromFile("bg.png")) { exit(-1); }

	if (!hhp.loadFromFile("hp.png")) { exit(-1); }
	if (!bblo.loadFromFile("blo.png")) { exit(-1); }
	if (!llife.loadFromFile("life.png")) { exit(-1); }
	if (!mini.loadFromFile("minimy.png")) { exit(-1); }
	if (!ssc.loadFromFile("score.png")) { exit(-1); }
	if (!scll.loadFromFile("scoreline.png")) { exit(-1); }

	if (!ll1.loadFromFile("l1.png")) { exit(-1); }
	if (!ll2.loadFromFile("l2.png")) { exit(-1); }
	if (!ll3.loadFromFile("l3.png")) { exit(-1); }
	if (!ppa.loadFromFile("pass.png")) { exit(-1); }

	if (!bjyy.loadFromFile("bj.wav"))exit(-1);
	bj.setBuffer(bjyy);
	bj.play();
	if (!fss.loadFromFile("fs.wav")) exit(-1);
	fs.setBuffer(fss);
	if (!boo.loadFromFile("boom.wav"))exit(-1);
	ex.setBuffer(boo);
	if (!boo2.loadFromFile("boom2.wav"))exit(-1);
	ex2.setBuffer(boo2);
}
void drawlife()
{
	minimy.setPosition(sf::Vector2f(75, 750));
	window.draw(minimy);
	if (life >= 2)
	{
		minimy.setPosition(sf::Vector2f(105, 750));
		window.draw(minimy);
	}
	if (life >= 3)
	{
		minimy.setPosition(sf::Vector2f(135, 750));
		window.draw(minimy);
	}
}
void drawmy()
{
	if (damage)
	{
		if (dam.getElapsedTime() > sf::seconds(0.6)) damage = 0;
		else
		{
			my.setColor(sf::Color(255, 0, 0));
			window.draw(my);
		}
	}
	else
	{
		my.setColor(sf::Color(200, 200, 200));
		window.draw(my);
	}
}
void movemy()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (p.x >= 0))
	{
		my.move(-0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (p.x <= 720))
	{
		my.move(0.1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (p.y >= 0))
	{
		my.move(0, -0.1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (p.y <= 694))
	{
		my.move(0, 0.1);
	}
	p = my.getPosition();
	for (int i = 1; i <= enemynum; i++)
	{
		if ((p.x > enemy[i].x - 60) && (p.x < enemy[i].x + 110) && (p.y > enemy[i].y - 92) && (p.y < enemy[i].y + 53) && (!enemy[i].h))
		{
			life--;
			if (life == 0)
			{
				lose = 1;
				clocklose.restart();
				ch[i].restart();
				enemy[i].h = 1;
				losex = p.x;
				losey = p.y;
			}
			else
			{
				crash = 1;
				losex = p.x;
				losey = p.y;
				clocklose.restart();
			}
		}
	}
}
void proshell()
{
	sf::Time s = cl.getElapsedTime();
	if (s >= sf::seconds(0.1))
	{
		cl.restart();
		if (atktype == 1)
		{
			shellnum += 2;
			shell[shellnum-1].x = p.x + 3;
			shell[shellnum-1].y = p.y +56;
			shell[shellnum].x= p.x + 66;
			shell[shellnum].y= p.y + 56;
			shell[shellnum-1].t = 1;
			shell[shellnum].t = 1;
			fs.play();
		}
		if (atktype == 2)
		{
			shellnum++;
			shell[shellnum].x = p.x + 30;
			shell[shellnum].y = p.y - 20;
            shell[shellnum].t = 2;
			ex2.play();
		}
	}
}
void proeshell()
{
	if (in1)
	{
		for (int i = 1; i <= enemynum; i++)
		{
			if (enemy[i].h) continue;
			sf::Time s = ces[i].getElapsedTime();
			if (s >= sf::seconds(0.5))
			{
				ces[i].restart();
				eshellnum += 2;
				eshell[eshellnum - 1].x = enemy[i].x + 1;
				eshell[eshellnum - 1].y = enemy[i].y + 72;
				eshell[eshellnum - 1].t = 1;
				eshell[eshellnum].x = enemy[i].x + 117;
				eshell[eshellnum].y = enemy[i].y + 72;
				eshell[eshellnum].t = 1;
			}
		}
	}
	if (in2)
	{
		for (int i = 1; i <= enemynum; i++)
		{
			if (enemy[i].h) continue;
			sf::Time s = ces[i].getElapsedTime();
			if (s >= sf::seconds(1.2))
			{
				ces[i].restart();
				eshellnum += 4;
				eshell[eshellnum - 1].x = enemy[i].x + 1;
				eshell[eshellnum - 1].y = enemy[i].y + 72;
				eshell[eshellnum - 1].t = 1;
				eshell[eshellnum].x = enemy[i].x + 117;
				eshell[eshellnum].y = enemy[i].y + 72;
				eshell[eshellnum].t = 1;
				eshell[eshellnum - 2].x = enemy[i].x + 0;
				eshell[eshellnum - 2].y = enemy[i].y + 72;
				eshell[eshellnum - 2].t = 2;
				eshell[eshellnum - 3].x = enemy[i].x + 130;
				eshell[eshellnum - 3].y = enemy[i].y + 72;
				eshell[eshellnum - 3].t = 3;
			}
		}
	}
	if (in3)
	{
		for (int i = 1; i <= enemynum; i++)
		{
			if (enemy[i].h) continue;
			sf::Time s = ces[i].getElapsedTime();
			if (s >= sf::seconds(0.9))
			{
				ces[i].restart();
				eshellnum += 4;
				eshell[eshellnum - 1].x = enemy[i].x + 1;
				eshell[eshellnum - 1].y = enemy[i].y + 72;
				eshell[eshellnum - 1].t = 1;
				eshell[eshellnum].x = enemy[i].x + 117;
				eshell[eshellnum].y = enemy[i].y + 72;
				eshell[eshellnum].t = 1;
				eshell[eshellnum - 2].x = enemy[i].x + 0;
				eshell[eshellnum - 2].y = enemy[i].y + 72;
				eshell[eshellnum - 2].t = 2;
				eshell[eshellnum - 3].x = enemy[i].x + 130;
				eshell[eshellnum - 3].y = enemy[i].y + 72;
				eshell[eshellnum - 3].t = 3;
			}
		}
	}
}
void moveshell()
{
	int i;
	if ((shellnum >= 1) && (shell[1].y<-10))
	{
		for (i = 1; i <= shellnum - 1; i++)
		{
			shell[i].x = shell[i + 1].x;
			shell[i].y = shell[i + 1].y;
			shell[i].t = shell[i + 1].t;
		}
		shellnum--;
	}
	for (i = 1; i <= shellnum; i++)
	{
		shell[i].y -= 0.2;
	}
}
void moveeshell()
{
	int i,n;
	zb b[200];
	n = 0;
	if (check.getElapsedTime() > sf::seconds(1))
	{
		for (i = 1; i <= eshellnum; i++)
		{
			if (eshell[i].y < 820)
			{
				n++;
				b[n].x = eshell[i].x;
				b[n].y = eshell[i].y;
				b[n].t = eshell[i].t;
			}
		}
		for (i = 1; i <= n; i++)
		{
			eshell[i].x = b[i].x;
			eshell[i].y = b[i].y;
			eshell[i].t = b[i].t;
		}
		eshellnum = n;
		check.restart();
	}
	for (i = 1; i <= eshellnum; i++)
	{
		if(eshell[i].t==1) eshell[i].y += 0.1;
		if (eshell[i].t == 2)
		{
			eshell[i].y += 0.1;
			eshell[i].x -= 0.05;
		}
		if (eshell[i].t == 3)
		{
			eshell[i].y += 0.1;
			eshell[i].x += 0.05;
		}
	}
}
void drawshell()
{
	for (int i = 1; i <= shellnum; i++)
	{
		if (shell[i].t == 1)
		{
			she.setPosition(sf::Vector2f(shell[i].x, shell[i].y));
			she.setColor(sf::Color(50, 233, 250));
			window.draw(she);
		}
		else
		{
			pao2.setPosition(sf::Vector2f(shell[i].x, shell[i].y));
			window.draw(pao2);
		}
	}
}
void draweshell()
{
	for (int i = 1; i <= eshellnum; i++)
	{
		e.setPosition(sf::Vector2f(eshell[i].x, eshell[i].y));
		window.draw(e);
	}
}
void checkshell()
{
	for (int i = 1; i <= shellnum; i++)
	{
		for (int j = 1; j <= enemynum; j++)
		{
			if (enemy[j].h) continue;
			if ((shell[i].x >= enemy[j].x) && (shell[i].x <= enemy[j].x + 130) && (shell[i].y >= enemy[j].y) && (shell[i].y <= enemy[j].y + 73))
			{
				if(shell[i].t==1) enemy[j].b--;
				else enemy[j].b -= 2;
				for (int k = i; k <= shellnum - 1; k++)
				{
					shell[k].x = shell[k + 1].x;
					shell[k].y = shell[k + 1].y;
					shell[k].t = shell[k + 1].t;
				}
				shellnum--;
				ck[j].restart();
				enemy[j].k = 1;
				if (enemy[j].b < 0)
				{
					score++;
					enemy[j].h = 1;
					ch[j].restart();
					ex.play();
				}
				break;
			}
		}
	}
	for (int i = 1; i <= eshellnum; i++)
	{
		if ((eshell[i].x >= p.x - 10) && (eshell[i].x <= p.x + 60) && (eshell[i].y >= p.y - 10) && (eshell[i].y <= p.y + 102))
		{
			for (int j = i; j <= eshellnum - 1; j++)
			{
				eshell[j].x = eshell[j + 1].x;
				eshell[j].y = eshell[j + 1].y;
				eshell[j].t = eshell[j + 1].t;
			}
			eshellnum--;
			dam.restart();
			damage = 1;
			blood--;
			if (blood < 0)
			{
				life--;
				if (life == 0)
				{
					lose = 1;
					clocklose.restart();
					losex = p.x;
					losey = p.y;
				}
				else
				{
					crash = 1;
					losex = p.x;
					losey = p.y;
					clocklose.restart();
				}
			}
		}
	}

}
void proememy()
{
	int n;
	bool b=1;
	while (b)
	{
		n = rand() % 670+1;
		b = 0;
		for(int i=1;i<=enemynum;i++)
		{ 
			if ((n >= (enemy[i].x - 130)) && (n <= enemy[i].x+130) && (-73 >= enemy[i].y-73) && (-73 <= enemy[i].y + 73)) b = 1;
			break;
		}
	}
	enemynum++;
	enemy[enemynum].x = n;
	enemy[enemynum].y = -73;
	if(in1)enemy[enemynum].b = 12;
	if(in2)enemy[enemynum].b = 16;
	if(in3)enemy[enemynum].b = 20;
	enemy[enemynum].k = 0;
	enemy[enemynum].h = 0;
}
void moveenemy()
{
	int i, n, j;
	float x, y, fx, fy;
	bool b;
	if ((enemynum >= 1) && (enemy[1].y > 800))
	{
		for (int j = 1; j <= enemynum - 1; j++)
		{
			enemy[j].x = enemy[j + 1].x;
			enemy[j].y = enemy[j + 1].y;
			enemy[j].b = enemy[j + 1].b;
			enemy[j].k = enemy[j + 1].k;
			enemy[j].h = enemy[j + 1].h;
			ch[j] = ch[j + 1];
		}
		enemynum--;
	}
	for (i = 1; i <= enemynum; i++)
	{   
		if (enemy[i].h) continue;
		enemy[i].y += 0.07;
    }
}
void drawenemy()
{
	for (int i = 1; i <= enemynum; i++)
	{
		if (enemy[i].h)
		{
			if (ch[i].getElapsedTime() > sf::seconds(2))
			{
				for (int j = i; j <= enemynum - 1; j++)
				{
					enemy[j].x = enemy[j + 1].x;
					enemy[j].y = enemy[j + 1].y;
					enemy[j].b = enemy[j + 1].b;
					enemy[j].k = enemy[j + 1].k;
					enemy[j].h = enemy[j + 1].h;
					ch[j] = ch[j + 1];
				}
				enemynum--;
				i--;
			}
			else
			{
				vividboom(i);
			}
			continue;
		}
		if(enemy[i].k)
		{
			if (ck[i].getElapsedTime() > sf::seconds(0.6)) enemy[i].k = 0;
			else
			{
				ene.setColor(sf::Color(255, 0, 0));
				ene.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
				window.draw(ene);
				continue;
			}
		}
		ene.setColor(sf::Color(0, 255, 255));
		ene.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(ene);
	}
}
void vividboom(int i)
{
	sf::Sprite s;
	if ((ch[i].getElapsedTime() >= sf::seconds(0)) && (ch[i].getElapsedTime() <= sf::seconds(0.1)))
	{
		s.setTexture(b1);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.1)) && (ch[i].getElapsedTime() <= sf::seconds(0.2)))
	{
		s.setTexture(b2);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.2)) && (ch[i].getElapsedTime() <= sf::seconds(0.3)))
	{
		s.setTexture(b3);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.3)) && (ch[i].getElapsedTime() <= sf::seconds(0.4)))
	{
		s.setTexture(b4);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.4)) && (ch[i].getElapsedTime() <= sf::seconds(0.5)))
	{
		s.setTexture(b5);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.5)) && (ch[i].getElapsedTime() <= sf::seconds(0.6)))
	{
		s.setTexture(b6);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.6)) && (ch[i].getElapsedTime() <= sf::seconds(0.7)))
	{
		s.setTexture(b7);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.7)) && (ch[i].getElapsedTime() <= sf::seconds(0.8)))
	{
		s.setTexture(b8);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.8)) && (ch[i].getElapsedTime() <= sf::seconds(0.9)))
	{
		s.setTexture(b9);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(0.9)) && (ch[i].getElapsedTime() <= sf::seconds(1)))
	{
		s.setTexture(b10);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1)) && (ch[i].getElapsedTime() <= sf::seconds(1.1)))
	{
		s.setTexture(b11);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.1)) && (ch[i].getElapsedTime() <= sf::seconds(1.2)))
	{
		s.setTexture(b12);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.2)) && (ch[i].getElapsedTime() <= sf::seconds(1.3)))
	{
		s.setTexture(b13);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.3)) && (ch[i].getElapsedTime() <= sf::seconds(1.4)))
	{
		s.setTexture(b14);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.4)) && (ch[i].getElapsedTime() <= sf::seconds(1.5)))
	{
		s.setTexture(b15);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.5)) && (ch[i].getElapsedTime() <= sf::seconds(1.6)))
	{
		s.setTexture(b16);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.6)) && (ch[i].getElapsedTime() <= sf::seconds(1.7)))
	{
		s.setTexture(b17);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.7)) && (ch[i].getElapsedTime() <= sf::seconds(1.8)))
	{
		s.setTexture(b18);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
	if ((ch[i].getElapsedTime() >= sf::seconds(1.8)) && (ch[i].getElapsedTime() <= sf::seconds(1.9)))
	{
		s.setTexture(b19);
		s.setPosition(sf::Vector2f(enemy[i].x, enemy[i].y));
		window.draw(s);
	}
}
void boommy()
{
	sf::Sprite s;
	if ((clocklose.getElapsedTime() >= sf::seconds(0)) && (clocklose.getElapsedTime() <= sf::seconds(0.1)))
	{
		s.setTexture(m1);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.1)) && (clocklose.getElapsedTime() <= sf::seconds(0.2)))
	{
		s.setTexture(m2);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.2)) && (clocklose.getElapsedTime() <= sf::seconds(0.3)))
	{
		s.setTexture(m3); 
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.3)) && (clocklose.getElapsedTime() <= sf::seconds(0.4)))
	{
		s.setTexture(m4);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.4)) && (clocklose.getElapsedTime() <= sf::seconds(0.5)))
	{
		s.setTexture(m5);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.5)) && (clocklose.getElapsedTime() <= sf::seconds(0.6)))
	{
		s.setTexture(m6);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.6)) && (clocklose.getElapsedTime() <= sf::seconds(0.7)))
	{
		s.setTexture(m7);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.7)) && (clocklose.getElapsedTime() <= sf::seconds(0.8)))
	{
		s.setTexture(m8);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.8)) && (clocklose.getElapsedTime() <= sf::seconds(0.9)))
	{
		s.setTexture(m9);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(0.9)) && (clocklose.getElapsedTime() <= sf::seconds(1)))
	{
		s.setTexture(m10);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1)) && (clocklose.getElapsedTime() <= sf::seconds(1.1)))
	{
		s.setTexture(m11);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.1)) && (clocklose.getElapsedTime() <= sf::seconds(1.2)))
	{
		s.setTexture(m12);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.2)) && (clocklose.getElapsedTime() <= sf::seconds(1.3)))
	{
		s.setTexture(m13);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.3)) && (clocklose.getElapsedTime() <= sf::seconds(1.4)))
	{
		s.setTexture(m14);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.4)) && (clocklose.getElapsedTime() <= sf::seconds(1.5)))
	{
		s.setTexture(m15);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.5)) && (clocklose.getElapsedTime() <= sf::seconds(1.6)))
	{
		s.setTexture(m16);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.6)) && (clocklose.getElapsedTime() <= sf::seconds(1.7)))
	{
		s.setTexture(m17);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.7)) && (clocklose.getElapsedTime() <= sf::seconds(1.8)))
	{
		s.setTexture(m18);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
	if ((clocklose.getElapsedTime() >= sf::seconds(1.8)) && (clocklose.getElapsedTime() <= sf::seconds(1.9)))
	{
		s.setTexture(m19);
		s.setPosition(sf::Vector2f(losex, losey));
		window.draw(s);
	}
}