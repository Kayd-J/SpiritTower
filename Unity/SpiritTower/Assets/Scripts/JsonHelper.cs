using System;
using System.Collections.Generic;
using Debug = UnityEngine.Debug;
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
        if (Spawner.objetosInstanciados != null) {
            wrapper.Objects = separateObjects(Spawner.objetosInstanciados);
        }
       
        return JsonUtility.ToJson(wrapper,false);
    }
    
    private static Objects[] separateObjects(List<Objecto> instanciados) {
        //Debug.Log(instanciados.Count);
        Objects[] res = new Objects[instanciados.Count];
        for (int i = 0; i < instanciados.Count; i++) {
            res[i] = instanciados[i].information;
        }
        return res;
    }

}

//Se encarga de recuperar toda la informacion necesaria del Json
[Serializable]
public class Wrapper
{
    public Player Player;
    public Enemies[] Enemies;
    public Objects[]  Objects;
    public Boss Boss;
}