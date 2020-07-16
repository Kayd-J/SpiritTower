using UnityEngine;
using UnityEngine.AI;


public class EnemyMovement : MonoBehaviour
{
    public Camera cam;
    public NavMeshAgent agent;
    Vector3 Enemymoves;

    // Update is called once per frame
    void Update()
    {

        if (Input.GetMouseButtonDown(0)) {
            Ray ray = cam.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if (Physics.Raycast(ray, out hit)) {
                //Mueve el agente
                Enemymoves = new Vector3(1.5f, 0f, 1.5f);
                agent.SetDestination(Enemymoves);
                
            }
        
        }
        
    }
}
