using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

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

    public static List<MapEnemy> enemiesInstanciados;
    public static List<Objecto> objetosInstanciados;
    public static int TresureCount;

    public Text treasureText;
    

    public void CheckOrMove(Enemies[] enemies, Objects[] objetos) {

        for (int i = 0; i < objetos.Length; i++)        {
            if (objetosInstanciados == null){
                objetosInstanciados = new List<Objecto>();
                addObject(objetos[i], i);
            }
            else{
                if (objetosInstanciados.Count < objetos.Length) {
                    addObject(objetos[i], i);
                }
                else {
                    //Update
                    updateObject(objetos[i]);                
                }
            }
        }
        updateText();
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
        Vector3 postition = new Vector3((float)enemy.posX + 0.5f, 0f, 19f - ((float)enemy.posY - 0.5f));
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
               enemiesInstanciados[i].entity.GetComponent<EnemyMovement>().move((float)enemy.posX + 0.5f, 19f -((float)enemy.posY - 0.5f));
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
            Vector3 postition = new Vector3((float)objeto.posX + 0.5f, 0f, 19f- ((float)objeto.posY - 0.5f));
            //instance the object
            GameObject instance = Instantiate(Jarron, transform.position + postition, transform.rotation);

            objetoEnJuego.entity = instance;
            objetosInstanciados.Add(objetoEnJuego);
        }
        else
        {//el ID es "K"
            //creates a "wrap" with both IngameObject and the information 
            Objecto objetoEnJuego = new Objecto();
            objetoEnJuego.information = objeto;
            //correct placement
            Vector3 postition = new Vector3((float)objeto.posX + 0.5f, 0f, 19- ((float)objeto.posY - 0.5f));
            //________________________________  |
            //instance the object  remember to  V  Change that
            GameObject instance = Instantiate(Cofre, transform.position + postition, transform.rotation);


            objetoEnJuego.entity = instance;
            objetosInstanciados.Add(objetoEnJuego);
        }

    }

    public void updateObject(Objects objeto) {
        for (int i = 0; i < objetosInstanciados.Count; i++)
        {
            if ((objetosInstanciados[i].information.posY == objeto.posY) && (objetosInstanciados[i].information.posX == objeto.posX))
            {
                objetosInstanciados[i].information.DEATH = objeto.DEATH;
            }
            
        }
    }


    private void voudUpdateVisualObject() { }

    private void updateText() {
        TresureCount = 0;
        int totalTreasures =0;
        for (int i = 0; i < objetosInstanciados.Count; i++) {
            if (objetosInstanciados[i].information.ID == "K") {
                totalTreasures++;

                //print(objetosInstanciados[i].information.DEATH);
                if (objetosInstanciados[i].information.DEATH)
                {
                    TresureCount++;
                }
            }

        }
        treasureText.text = totalTreasures.ToString() + "/"+ TresureCount.ToString();

        
    }

}