using UnityEngine;
using UnityEngine.AI;


public class EnemyMovement : MonoBehaviour
{
    public Camera cam;
    public NavMeshAgent agent;
    Vector3 Enemymoves;


    // Update is called once per frame
    void Update(){
            
    }

    public void move(float x, float y) {
        Enemymoves = new Vector3(x, 0f, y);
        agent.SetDestination(Enemymoves);
    }

}
