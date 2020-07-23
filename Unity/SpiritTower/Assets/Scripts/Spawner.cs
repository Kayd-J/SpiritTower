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
    private static MapEnemy[] enemiesInstanciados;
    private static Objecto[] cofresInstanciados;
    private static Objecto[] jarronesInstanciados;
    public static int TresureCount;

    public void CheckOrMove(Enemies[] enemies, Objects[] objetos) {
        
        for (int i = 0; i < objetos.Length; i++)
        {
            //TresureCount++;
            if (jarronesInstanciados != null)
            {
                
            }
            else
            {
                addObject(objetos[i],i);                
            }
        }

        for (int i = 0; i < enemies.Length; i++) {
            if (enemiesInstanciados != null) {
                moveEnemies(enemies[i]);
            }
            else {
                createEnemies(enemies[i],i);            
            }
        }

    }

    private void createEnemies(Enemies enemy, int i) {

        string type = enemy.ID;
        enemiesInstanciados[i] = new MapEnemy();
        enemiesInstanciados[i].information = enemy;
        Vector3 postition = new Vector3((float)enemiesInstanciados[i].information.posX - 0.5f, 0f, (float)enemiesInstanciados[i].information.posY - 0.5f);

        switch (type) {
            //espectros
            case "A":
                enemiesInstanciados[i].entity = Instantiate(typeofEspectro(enemy.COLOR),transform.position + postition, transform.rotation);
                break;
            case "B":
                enemiesInstanciados[i].entity = Instantiate(typeofEspectro(enemy.COLOR), transform.position + postition, transform.rotation);
                break;
            case "C":
                enemiesInstanciados[i].entity = Instantiate(typeofEspectro(enemy.COLOR), transform.position + postition, transform.rotation);
                break;

            //Ratones
            case "R":
                enemiesInstanciados[i].entity = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
            case "T":
                enemiesInstanciados[i].entity = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
            case "X":
                enemiesInstanciados[i].entity = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;
            case "N":
                enemiesInstanciados[i].entity = Instantiate(Raton, transform.position + postition, transform.rotation);
                break;

            //Ojos espectrales
            case "S":
                enemiesInstanciados[i].entity = Instantiate(Ojo, transform.position + postition, transform.rotation);
                break;
            case "E":
                enemiesInstanciados[i].entity = Instantiate(Ojo, transform.position + postition, transform.rotation);
                break;

            //Chuchu
            case "H":
                enemiesInstanciados[i].entity = Instantiate(ChuChu, transform.position + postition, transform.rotation);
                break;
        }
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

    private void moveEnemies(Enemies enemy)
    {
        for (int i = 0; i < enemiesInstanciados.Length; i++)
        {
            if (enemy.ID == enemiesInstanciados[i].information.ID)
            {
                enemiesInstanciados[1].entity.GetComponent<EnemyMovement>().move((float)enemy.posX + 0.5f, (float)enemy.posY + 0.5f);
            }
        }


    }
    private void killEnemies(string ID) { }

    private void addObject(Objects objeto, int i) {

        if (objeto.ID == "J")
        {
            jarronesInstanciados[i] = new Objecto();
            jarronesInstanciados[i].information = objeto;

            Vector3 postition = new Vector3((float)objeto.posX - 0.5f, 0f, (float)objeto.posY - 0.5f);
            GameObject instance = Instantiate(Jarron, transform.position + postition, transform.rotation);
            jarronesInstanciados[i].entity = instance;

        }
        else {//el ID es "K"
            cofresInstanciados[i] = new Objecto();
            cofresInstanciados[i].information = objeto;

            Vector3 postition = new Vector3((float)objeto.posX - 0.5f, 0f, (float)objeto.posY - 0.5f);
            GameObject instanci = Instantiate(Cofre, transform.position + postition, transform.rotation);
            cofresInstanciados[i].entity = instanci;
        }

    }
    private void updateObject(Objects objeto) {
        switch (objeto.ID)
        {
            case "J":
                for (int i = 0; i < jarronesInstanciados.Length; i++) {
                    if((jarronesInstanciados[i].information.posY == objeto.posY) && (jarronesInstanciados[i].information.posX == objeto.posX))
                    {
                        jarronesInstanciados[i].information.DEATH = objeto.DEATH;
                    }
                }
                break;
            case "K":
                for (int i = 0; i < cofresInstanciados.Length; i++)
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







