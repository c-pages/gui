uniform sampler2D   texture;
uniform vec4        rectMasque;
uniform bool        aTexture    = true;


void main() {

    // la couleur du rectangle (FillColor)
    vec4 color = gl_Color;
    vec2 pos   = gl_FragCoord;

    vec4 masque;
    if ( pos.x < rectMasque.x
    ||   pos.x > rectMasque.x + rectMasque.z
    ||   pos.y < rectMasque.y - rectMasque.w
    ||   pos.y > rectMasque.y )
        masque = (0,0,0,0);
    else
        masque = (1,1,1,1);


    if ( aTexture ) {
        // la couleur du pixel de la texture
        vec4 pixel = texture2D(texture, gl_TexCoord[0].st);

        gl_FragColor = pixel * color * masque;
    } else {

        gl_FragColor = color * masque;
    }

}




//uniform sampler2D   texture;
//uniform vec2        clipPos     = (0,0);
//uniform vec2        clipTaille  = (-1,-1);
//uniform bool        aTexture    = true;
//
//void main() {
//
//    // la couleur du rectangle (FillColor)
//    vec4 color = gl_Color;
//    vec2 pos   = gl_FragCoord;
//
//    vec4 masque;
//    if ( pos.x < clipPos.x
//    ||   pos.x > clipPos.x + clipTaille.x
//    ||   pos.y < clipPos.y - clipTaille.y
//    ||   pos.y > clipPos.y )
//        masque = (0,0,0,0);
//    else
//        masque = (1,1,1,1);
//
//
//    if ( aTexture ) {
//        // la couleur du pixel de la texture
//        vec4 pixel = texture2D(texture, gl_TexCoord[0].st);
//
//        gl_FragColor = pixel * color * masque;
//    } else {
//
//        gl_FragColor = color * masque;
//    }
//
//}
//
//
//
