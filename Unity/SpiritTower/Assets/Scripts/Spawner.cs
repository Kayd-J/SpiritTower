using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    public GameObject Jarron;
    public GameObject Cofre;
    public GameObject Boss;
    public GameObject ChuChu;
    public GameObject Ojo;
    public GameObject Raton;
    public GameObject EGris;
    public GameObject EAzul;
    public GameObject ERojo;
    private static List<MapEnemy> enemiesInstanciados;
    private static List<Objecto> cofresInstanciados;
    private static List<Objecto> jarronesInstanciados;
    public static int TresureCount;

    public void CheckOrMove(Enemies[] enemies, Objects[] objetos) {

        for (int i = 0; i < objetos.Length; i++)        {
            if (jarronesInstanciados == null){
                jarronesInstanciados = new List<Objecto>();
                addObject(objetos[i], i);
            }
            else{
                if (jarronesInstanciados.Count < objetos.Length) {
                    addObject(objetos[i], i);
                }
                else {
                    //Update
                    updateObject(objetos[i]);                
                }
            }
        }
        for (int i = 0; i < enemies.Length; i++)
        {
            if (enemiesInstanciados == null){
                enemiesInstanciados = new List<MapEnemy>();
                createEnemies(enemies[i]);
            }
            else
            {
                if (enemiesInstanciados.Count < enemies.Length)
                {
                    createEnemies(enemies[i]);
                }
                else
                {
                    //Update
                    updateEnemies(enemies[i]);
                }
            }
        }
    }

    private void createEnemies(Enemies enemy) {
        //creates a "wrap" with both IngameObject and the information 
        MapEnemy IngameEnemy = new MapEnemy();
        IngameEnemy.information = enemy;
        //correct placement
        Vector3 postition = new Vector3((float)enemy.posX - 0.5f, 0f, (float)enemy.posY - 0.5f);
        //instance the object  
        string type = enemy.ID;
        GameObject instance;
        switch (type) {
            //espectros
            case "A":
                instance = Instantiate(typeofEspectro(enemy.COLOR),transform.position + postition, transform.rotation);
                break;
            case "B":
                instance = Instantiate(typeofEspectro(enemy.COLOR), transform.position + postition, transform.rotation);
                break;
            case "C":
                instance = Instantiate(typeofEspectro(enemy.COLOR), transform.position + postition, transform.rotation);
                break;

            //Ratones
            case "R":
                instance = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
            case "T":
                instance = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
            case "X":
                instance = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
            case "N":
                instance = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;

            //Ojos espectrales
            case "S":
                instance = Instantiate(Ojo, transform.position + postition, transform.rotation);
                break;
            case "E":
                instance = Instantiate(Ojo, transform.position + postition, transform.rotation);
                break;

            //Chuchu
            case "H":
                instance = Instantiate(ChuChu, transform.position + postition, transform.rotation);
                break;
            default:
                instance = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
        }
        IngameEnemy.entity = instance;
        enemiesInstanciados.Add(IngameEnemy);


    }
    private GameObject typeofEspectro(string tipo) {
        switch (tipo) {
            case "r":
                return ERojo;
            case "b":
                return EAzul;
            case "g":
                return EGris;
            default:
                return EGris;
        }
    
    }

    private void updateEnemies(Enemies enemy)
    {
        for (int i = 0; i < enemiesInstanciados.Count; i++)
        {
            if (enemy.ID == enemiesInstanciados[i].information.ID)
            {
               enemiesInstanciados[i].entity.GetComponent<EnemyMovement>().move((float)enemy.posX + 0.5f, (float)enemy.posY + 0.5f);
            }
        }
    }

    private void addObject(Objects objeto, int i) {
        if (objeto.ID == "J")
        {
            //creates a "wrap" with both IngameObject and the information 
            Objecto objetoEnJuego = new Objecto();
            objetoEnJuego.information = objeto;
            //correct placement
            Vector3 postition = new Vector3((float)objeto.posX - 0.5f, 0f, (float)objeto.posY - 0.5f);
            //instance the object
            GameObject instance = Instantiate(Jarron, transform.position + postition, transform.rotation);


            objetoEnJuego.entity = instance;
            jarronesInstanciados.Add(objetoEnJuego);

        }
        else
        {//el ID es "K"
            //creates a "wrap" with both IngameObject and the information 
            Objecto objetoEnJuego = new Objecto();
            objetoEnJuego.information = objeto;
            //correct placement
            Vector3 postition = new Vector3((float)objeto.posX - 0.5f, 0f, (float)objeto.posY - 0.5f);
            //________________________________  |
            //instance the object  remember to  V  Change that
            GameObject instance = Instantiate(Jarron, transform.position + postition, transform.rotation);


            objetoEnJuego.entity = instance;
            jarronesInstanciados.Add(objetoEnJuego);
        }

    }

    private void updateObject(Objects objeto) {
        switch (objeto.ID)
        {
            case "J":
                for (int i = 0; i < jarronesInstanciados.Count; i++) {
                    if((jarronesInstanciados[i].information.posY == objeto.posY) && (jarronesInstanciados[i].information.posX == objeto.posX))
                    {
                        jarronesInstanciados[i].information.DEATH = objeto.DEATH;
                    }
                }
                break;
            case "K":
                for (int i = 0; i < cofresInstanciados.Count; i++)
                {
                    if ((cofresInstanciados[i].information.posY == objeto.posY) && (cofresInstanciados[i].information.posX == objeto.posX))
                    {
                        cofresInstanciados[i].information.DEATH = objeto.DEATH;
                    }
                }
                break;
        }
    }
}

public class MapEnemy{
        public GameObject entity;
        public Enemies information;
}

public class Objecto
{
    public GameObject entity;
    public Objects information;
}







