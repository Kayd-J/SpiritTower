using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    [SerializeField] GameObject Jarron;
    [SerializeField] GameObject Cofre;
    [SerializeField] GameObject Boss;
    [SerializeField] GameObject ChuChu;
    [SerializeField] GameObject Ojo;
    [SerializeField] GameObject Raton;
    [SerializeField] GameObject EGris;
    [SerializeField] GameObject EAzul;
    [SerializeField] GameObject ERojo;
    private Enemies[] enemiesInstanciados;
    private Cofres[] cofresInstanciados;
    private Jarrones[] jarronesInstanciados;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public static void CheckOrMove(Enemies[] enemies,Cofres[] cofres, Jarrones[] jarrones) {

        for (int i = 0; i < enemies.Length; i++){
            //Debug.Log(deserializados[i].ID);
        }


    }


}
