using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    [SerializeField] static GameObject Jarron;
    [SerializeField] static GameObject Cofre;
    [SerializeField] static GameObject Boss;
    [SerializeField] static GameObject ChuChu;
    [SerializeField] static GameObject Ojo;
    [SerializeField] static GameObject Raton;
    [SerializeField] static GameObject EGris;
    [SerializeField] static GameObject EAzul;
    [SerializeField] static GameObject ERojo;
    private static Enemies[] enemiesInstanciados;
    private static Chest[] cofresInstanciados;
    private static Jar[] jarronesInstanciados;
    public static int TresureCount;

    public void CheckOrMove(Enemies[] enemies, Cofres[] cofres, Jarrones[] jarrones) {
        TresureCount = 0;

        /**
        for (int i = 0; i < cofres.Length; i++){
            TresureCount++;
            if (cofresInstanciados != null)
            {
                //si ya existe la lista nada mas les actualizo el DEATH
                cofresInstanciados[i].information.DEATH = cofres[i].DEATH;
            }
            else {
                cofresInstanciados[i] = new Cofres();
                cofresInstanciados[i].information = cofres[i];

                Vector3 postition = new Vector3((float)cofres[i].posX - 0.5f, 0f, (float)cofres[i].posY - 0.5f);
                GameObject instance = Instantiate(Cofre, transform.position+postition, transform.rotation);
                cofresInstanciados[i].entity = instance;
            }

        }**/


        /**
        for (int i = 0; i < jarrones.Length; i++)
        {
            TresureCount++;
            if (jarronesInstanciados != null)
            {
                //si ya existe la lista nada mas les actualizo el DEATH
                jarronesInstanciados[i].information.DEATH = jarrones[i].DEATH;
            }
            else
            {
                jarronesInstanciados[i] = new Jar();
                jarronesInstanciados[i].information = jarrones[i];

                Vector3 postition = new Vector3((float)jarrones[i].posX - 0.5f, 0f, (float)jarrones[i].posY - 0.5f);
                GameObject instance = Instantiate(Jarron, transform.position + postition, transform.rotation);
                jarronesInstanciados[i].entity = instance;
            }

        }**/

        for (int i = 0; i < enemies.Length; i++) {


            string ID = enemies[i].ID;

            //Debug.Log(deserializados[i].ID);

            
        }

    }


    private void moveEnemies (string ID) {}
    private void createEnemies(string ID) {}
    private void killEnemies(string ID) { }

}

    public class Chest { 
        public GameObject entity;
        public Cofres information;
    }
    public class Jar{
        public GameObject entity;
        public Jarrones information;
    }
    public class MapEnemy{
        public GameObject entity;
        public Jarrones information;
    }




