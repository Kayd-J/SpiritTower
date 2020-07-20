using System;
using UnityEngine;
[Serializable]
public class Player
{
    public int Health=100;
    public int Score=10;
    public int posX=2;
    public int posY=3;
    public bool Shield=false;
    public bool Sword=true;
}

[Serializable]
public class Enemies
{
    public string ID = "A";
    public bool DEATH = false ;
    public int posX;
    public int posY ;
}

[Serializable]
public class Trampas
{
    public string ID = "A";
    public bool DEATH = false;
    public int posX;
    public int posY;
}

