#include <stdio.h>
#include <cassert>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "Image.hpp"
#include "utils.hpp"
#include "Edge.hpp"
#include "Noeud.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    //**************************************************************************************
    //                             Open image using OpenCV
    //**************************************************************************************
   
    string path2img = "/home/dude/Documents/Projets/ip_cpp/Test/resource/clem.jpg";

    Mat image;
    image = imread( path2img, 1 );
    info(image);

    Mat imout = Mat::zeros(image.rows, image.cols, CV_8U);
    color2grey(image, imout); // custom function


    //**************************************************************************************
    //                           CONVERSION FROM OPENCV 
    //**************************************************************************************
    Image<uint8_t> im2(image.rows, image.cols, 1);

    for(int i=0; i<image.rows; ++i)
        for(int j=0; j<image.cols; ++j)
            im2[i*image.cols + j] = imout.at<uint8_t>(i,j);

    //**************************************************************************************
    //                                PROCESSING
    //**************************************************************************************

    im2 /= 2;
    int imW = 4;//im2.width();
    int imH = 3;//im2.height(); 

    // 1. Initialisation du graphe et des arcs
    int graphSize = imW*imH;
    int edgesNb   = 2*imW*imH - imH - imW;


    Noeud graphe[graphSize];
    //Noeud * graphe = (Noeud*) malloc(sizeof(Noeud)*graphSize); // Ces deux tab stockent les vrais Node/Edge
    Edge edges[edgesNb];
    //Edge * edges = (Edge*) malloc(sizeof(Edge)*edgesNb);

    for(int i=0; i<graphSize; i++) // Init des noeuds 
        graphe[i].index  = i;
   
    for (int i = 0; i < edgesNb; ++i) // Init des arcs
        edges[i].index = i;
    //**************************************************************************************
    // 1.1 Association des noeuds et des arcs
    //**************************************************************************************
    int index_edges = 0;
    int index_node  = 0;
    // Creation des arcs horizontaux
    for(int i=0; i<imH; ++i){
        for(int j=0; j<imW-1; ++j){
            index_node = i*imW + j;
            graphe[index_node].setEdge(&(edges[index_edges]), &(graphe[index_node+1]) ); //Bi-directional edge
            ++index_edges;
        }
    }

    // Creation des arcs verticaux
    for(int i=0; i<imH-1; ++i){
        for(int j=0; j<imW; ++j){
            index_node = i*imW + j;
            graphe[index_node].setEdge(&(edges[index_edges]), &(graphe[index_node+imW]) ); //Bi-directional edge
            ++index_edges;
        }
    }

    //**************************************************************************************
    // 2. Attribuer un poids a tous les arcs
    //**************************************************************************************

    for(int i=0; i<edgesNb; i++)
        edges[i].capacity = i;

 
    //**************************************************************************************
    // 3. Attribuer une hauteur à tous les noeuds (+ source + puit)
    //**************************************************************************************



    //**************************************************************************************
    // 4. Push initial : saturation de tous les arcs depuis la source
    //**************************************************************************************



    //**************************************************************************************
    // 5. On remplit la queue de tous les noeuds actifs
    //**************************************************************************************



    //**************************************************************************************
    // 6. Itérativement : 
    //**************************************************************************************
    // 6.1 On prend le premier noeud actif. (head de la queue)
    // 6.2 On incrémente sa hauteur de 1
    // 6.3 Push dans chaque noeud possible. (par ordre de hauteur décroissant si possible)
    // 6.4 Si pendant ces opérations de push l'excès d'un voisin devient non-nul, le rajouter aux "actifs" (à la fin)
    // 6.5 Tant que excès > 0, augmenter sa hauteur
    // 6.6 Quand excès est nul, retirer de la queue

    // Heuristiques:
    // 1. Gap heuristique : S'il y a une hauteur 0 < N < |V|, telle qu'aucun noeud ne soit à cette hauteur
    //      alors tous les noeuds N < h(u) < |V| ont été déconnectés de T, donc on peut leur affecter h(u) = |V|+1
    // 2. Global relabel (cf GOldberg)

    //**************************************************************************************
    //                         CONVERSION TO OPENCV 
    //**************************************************************************************
    for(int i=0; i<image.rows; ++i)
        for(int j=0; j<image.cols; ++j)
            imout.at<uint8_t>(i,j) = im2[i*image.cols + j];

    // display(imout);

    return 0;
}

