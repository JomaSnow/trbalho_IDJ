#ifndef VEC2_H
#define VEC2_H

/*
Lembre-se trabalharemos com um eixo y que cresce para baixo, e que
as funções de trigonometria da biblioteca padrão usam ângulos em radianos.
*/
class Vec2 {

public:
    float x, y;
    Vec2();
    Vec2(float x, float y);
    Vec2* addVecs(Vec2* v1, Vec2* v2);
    Vec2* subtractVecs(Vec2* v1, Vec2* v2);
    Vec2* multiplyByScalar(Vec2* v1, float s);
    float getMagnitude();

    /*
      Funções recomendadas ainda pendentes:

        Cálculo do vetor normalizado
        Distância entre um ponto e outro
        Inclinação de um vetor em relação ao eixo x
        Inclinação da reta dada por dois pontos
        Rotação em um determinado ângulo
        Soma de Rect com Vec2
        Obter coordenadas do centro de um retângulo
        Distância entre o centro de dois Rects
        Saber se um ponto está dentro de um Rect
        Operadores de atribuição, soma, subtração
*/

};

#endif // VEC2_H
