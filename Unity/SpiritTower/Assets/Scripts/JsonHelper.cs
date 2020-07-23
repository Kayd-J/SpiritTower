using System;
using UnityEngine;
public static class JsonHelper
{
    public static Wrapper FromJson(string json)
    {
        Wrapper wrapper = JsonUtility.FromJson<Wrapper>(json);
        return wrapper;
    }

    public static string ToJson(Player state, Enemies[] arrayTwo, bool prettyPrint)
    {
        Wrapper wrapper = new Wrapper();
        wrapper.Player = state;
        wrapper.Enemies = arrayTwo;
        return JsonUtility.ToJson(wrapper,false);
    }

}

//Se encarga de recuperar toda la informacion necesaria del Json
[Serializable]
public class Wrapper
{
    public Player Player;
    public Enemies[] Enemies;
    public Objects[]  Objects;
}