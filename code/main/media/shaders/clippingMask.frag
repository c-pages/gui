
uniform sampler2D texture;
uniform vec2 clipPos;
uniform vec2 clipTaille;

void main() {
    vec2 pos      = gl_FragCoord;


    // récupère le pixel dans la texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec4 color = gl_Color;


    // invisible si hors du clip
    if ( pos.x < clipPos.x
    ||   pos.x > clipPos.x + clipTaille.x
    ||   pos.y < clipPos.y - clipTaille.y
    ||   pos.y > clipPos.y )
        pixel.a= 0;

    // et multiplication avec la couleur pour obtenir le pixel final
//    gl_FragColor =  color * ( 1,1,1,pixel.a);
    gl_FragColor =   gl_Color;

}




























