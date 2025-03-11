#include "pch.h"
#include "SADXModLoader.h"
#include "Creditos.h"
#include "SADXStructsNew.h"
#include <string>

const char MyString[] = "Ass";

HMODULE DCconversion = GetModuleHandle(L"DCMods_Main");
bool CreditsLoaded = true;

void ReplaceHint(int level, int hint, const char* message, int time)
{
    HintTexts[5 * SPANISH][hint].Text->Message = message;
    HintTexts[5 * SPANISH][hint].Text->Time = time;
}

#define ReplacePNG_Common(a) do { \
	_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\pvr_common\\index.txt", path); \
	helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)

#define ReplacePNG_StageE(a) do { \
	_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\pvr_stage_en\\index.txt", path); \
	helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)

extern "C" __declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
extern "C" __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions & helperFunctions)
{

    WriteData((const char**)0x504B5B, "Crear Archivo");

    //Bosses
    WriteData((const char**)0x5482A8, "Caos 0");
    WriteData((const char**)0x54CCFE, "Caos 2");
    WriteData((const char**)0x5509DC, "Caos 4");
    WriteData((const char**)0x559872, "Caos 6");
    WriteData((const char**)0x56037F, "Caos Perfecto");

    //Hedgehog Hammer english
    WriteData((const char**)0x62616D, "MAYOR PUNTAJE");
    WriteData((const char**)0x626197, "PUNTOS");
    WriteData((const char**)0x6261CA, "PUNTOS");
    WriteData((const char**)0x626215, "DOCTOR EGGMAN");
    WriteData((const char**)0x626279, "INICIAR");
    WriteData((const char**)0x6262C9, "TIEMPO");
    WriteData((const char**)0x6262D8, "CONTADOR");
    WriteData((const char**)0x626319, "PUNTOS");
    WriteData((const char**)0x626362, "PUNTOS");
    WriteData((const char**)0x626401, "FIN DEL JUEGO");
    WriteData((const char**)0x626458, "FELICIDADES");
    WriteData((const char**)0x6264C0, "AHORA TIENES LA PLUMA DE GUERRERA");
    WriteData((const char**)0x6264D3, "AHORA TIENES EL MARTILLO LARGO");
    WriteData((const char**)0x62652A, "HAS OBTENIDO EL MAYOR PUNTAJE");
    WriteData((const char**)0x6283F5, "FIN DEL JUEGO");
    WriteData((const char**)0x7595DF, "PRESIONA A PARA MATAR AL CHAO");

    // Game menu messages
    WriteData((const char**)0x917DCC, "�Est�s seguro de que quieres volver\na la configuraci�n por defecto?"); // sp
    WriteData((const char**)0x917DE8, "Volver atr�s"); // sp
    WriteData((const char**)0x917DFC, "�Guardar en este bot�n?"); // sp
    WriteData((const char**)0x917E10, "Pulsa el bot�n que quieres guardar"); // sp
    WriteData((const char**)0x90C4AC, "Se terminar� la partida y volver� al\nselector de personajes. �De acuerdo?"); // sp
    WriteData((const char**)0x90C4C0, "Se terminar� la etapa y volver�s al Campo\nde Aventura. �De acuerdo?"); // sp
    WriteData((const char**)0x90C4D4, "Terminar� la partida y volver�s al men�\nprincipal. �De acuerdo?"); // sp

    // Unlock minigame message
    WriteData((const char**)0x4B54FC, "'%s'\nha sido a�adido a la lista."); // sp

    // New lure messages
    WriteData((const char**)0x9818AC, "\a�Un anzuelo mejor!"); // sp 
    WriteData((const char**)0x9818B0, "\a��salo para pescar peces m�s grandes!"); // sp

    // Keys messages
    WriteData((const char**)0x111C6A0, "\aLa llave est� flotando."); // sp
    WriteData((const char**)0x111C678, "\aEsta debe de ser otra llave..."); // sp
    WriteData((const char**)0x7D3BE1, "\aUna estatua de plata...\nParece una llave."); // sp
    WriteData((const char**)0x7D3BA2, "\aUna estatua de oro...\nParece una llave."); // sp
    WriteData((const char**)0x7D3B5B, "\aLa Piedra de Viento... Parece una llave.\nEl grabado debe de significar algo."); // sp
    WriteData((const char**)0x7D3B10, "\aLa Piedra de Hielo... Parece una llave.\nQuiz� pueda usarla en las Ruinas M�sticas."); // sp
    WriteData((const char**)0x2BBF540, "\aLa Piedra de Hielo... Parece una llave.\nQuiz� pueda usarla en las Ruinas M�sticas."); // sp

    // Deleting file messages    
    WriteData((const char**)0x2CD7A48, "\aAceptar"); // sp
    WriteData((const char**)0x2CD7A10, "\aCancelar");
    WriteData((const char**)0x2CD7A70, "\aBorrar");
    WriteData((const char**)0x10D7958, "\t\tBorrado."); // sp
    WriteData((const char**)0x10D796C, "\t\tError al borrar."); // sp

    // Monkey Detonator messages
    WriteData((const char**)0x111CB5C, "\a'Interruptor Para Destruir Monos'\n"); // sp
    WriteData((const char**)0x111CB60, "\a'Pulsar para destruir.'"); // sp
    WriteData((const char**)0x111CB30, "\a�Interruptor encendido!"); // sp
    WriteData((const char**)0x111CB08, "\aEl bot�n fue accionado,\npero nada ha ocurrido."); // sp
    WriteData((const char**)0x111CAE0, "\aEl bot�n fue accionado,\npero nada ha ocurrido."); // sp

    // Station Square cards messages
    WriteData((const char**)0x2BC07C0, "\a�Una tarjeta de identificaci�n!\nAhora puedo entrar en ese edificio."); // sp
    WriteData((const char**)0x2BC07E8, "\aIdentificaci�n comprobada"); // sp
    WriteData((const char**)0x2BBF480, "\a�Una entrada! Ahora puedo entrar\nen Twinkle Park."); // sp 
    WriteData((const char**)0x2BBF468, "\a�Bienvenido al Twinkle Circuit!"); // sp

    // Tikal's messages
    WriteData((const char**)0x88C740, "\a�Por aqu�!"); // sp
    WriteData((const char**)0x8033D4, "\a�Ten cuidado! Planea algo m�s."); // sp

    // Chaos 0  (when timer is 01:00:00)
    WriteData((const char**)0x7FD52C, "\a�Salta, y vuelve a pulsar el bot�n de\nsalto para hacer un ataque teledirigido!");
    WriteData((const char**)0x7FD57C, "\aSu cabeza es su punto d�bil.");

    // Chaos 2
    WriteData((const char**)0x7FD970, "\a�Ataca la cabeza de Caos\ncuando est� desprevenido!");

    WriteData((const char**)0x7FD990, ""); // if restart twice and timer is 01:00:00
    WriteData((const char**)0x7FD9C0, "\a�Para atacar, planea o usa tu ataque giratorio,\npara da�ar su n�cleo!");

    WriteData((const char**)0x7FD9E0, ""); // if restart twice and hit chaos 2 times 
    WriteData((const char**)0x7FDA10, "\a�Puedes golpear las burbujas de agua!");

    // Chaos 4
    WriteData((const char**)0x7FE460, "\a�Ataca a Caos cuando saque la cabeza!");

    // Chaos 6
    WriteData((const char**)0x7FEBB0, "\aSi pudieras paralizar a Caos...\nPiensa en c�mo hacerlo.");
    WriteData((const char**)0x7FEC08, "\aToma las bombas que tire Eggman\ny l�nzalas hacia Caos.");
    WriteData((const char**)0x7FEC58, "\a�Apunta a la rana\ny lanza tu ca�a!"); // sp
    WriteData((const char**)0x7FECC0, "\a�Cuando Caos se acerque a ti, esa");
    WriteData((const char**)0x7FECC8, "\aes la oportunidad\nde lanzar tu ca�a!");

    // Egg Walker
    WriteData((const char**)0x801D64, "\aEl Egg M�vil tiene un punto d�bil.\nAt�calo cuando est� cerca.");

    WriteData((const char**)0x802CB0, "");
    WriteData((const char**)0x802CD0, ""); // after 1st tips and if only hit boss' legs

    WriteData((const char**)0x802D20, "\aAtaca sus piernas\ny as� perder� el equilibrio.");
    WriteData((const char**)0x802D30, "\aNo apuntes s�lo a las piernas.\n�Apunta a la cabina!");

    // Egg Viper
    WriteData((const char**)0x803494, "\aEggman est� al otro lado\ndel concentrador de energ�a.");
    WriteData((const char**)0x8034A4, "\aHaz m�ltiples ataques teledirigidos,");
    WriteData((const char**)0x8034B4, "\ay ataca la cabina.");

    WriteData((const char**)0x8033D4, ""); // if you take damage twice from a spinning thing
    WriteData((const char**)0x8034C4, "\aCon una cadena de ataques\nllegar�s a la cabina.");

    // ZERO (when timer is 01:00:00)
    WriteData((const char**)0x8046F4, "\aDebe tener un punto d�bil en alguna parte.");
    WriteData((const char**)0x804704, "\a�Contin�a atacando y encu�ntralo!");

    // Perfect Chaos
    WriteData((const char**)0x80055C, "\aAl alcanzar la m�xima velocidad,\nte envolver�s en un bola de fuego.");
    WriteData((const char**)0x800564, "\a�Con eso da�ar�s a Caos!");

#pragma region sp
    WriteData((const char**)0x2BC5808, "El objetivo es encontrar el");
    WriteData((const char**)0x2BC580C, "\"objeto de la misi�n\" en el");
    WriteData((const char**)0x2BC5810, "Campo de Aventura. Usa la pista");
    WriteData((const char**)0x2BC5814, "que se muestra a continuaci�n");
    WriteData((const char**)0x2BC5818, "para completar la misi�n.");

    WriteData((const char**)0x2BC581C, "Al tocar el \"objeto de la");
    WriteData((const char**)0x2BC5820, "misi�n\" se mostrar� una");
    WriteData((const char**)0x2BC5824, "pista. Tendr�s que adivinar a");
    WriteData((const char**)0x2BC5828, "d�nde ir y qu� hacer para");
    WriteData((const char**)0x2BC582C, "poder completar la misi�n.");

    WriteData((const char**)0x2BC5830, "Hay 60 misiones con 6");
    WriteData((const char**)0x2BC5834, "personajes (Sonic, Tails,");
    WriteData((const char**)0x2BC5838, "Knuckles, Amy, E-102, Big).");

    WriteData((char*)0x1708470, "�Trae al hombre que\nest� delante de la\nhamburguesas chidas!");
    WriteData((char*)0x1708540, "�Atrapa el globo en los\ncielos de las Ruinas M�sticas!");
    WriteData((char*)0x1708610, "�Consigue 100 anillos\ny ve hacia la valla de\nSonic que est� al\nlado de la piscina!");
    WriteData((char*)0x17086E0, "�No paran de crecer\nmalas hierbas en este\nlugar! �Tengo que\neliminarlas!");
    WriteData((char*)0x17087B0, "�He perdido mi globo!\n��Ahora est� ah� arriba!");
    WriteData((char*)0x1708880, "�Se est� ahogando!\n�Ayuda al hombre que\nest� en el agua!");
    WriteData((char*)0x1708950, "Metal Sonic est� solo y\nnecesita un amigo...\nPresta atenci�n.");
    WriteData((char*)0x1708A20, "�La medalla se cay�\nah�! �Nada de aparcar\nen sitios prohibidos!");
    WriteData((char*)0x1708AF0, "Atrapa el globo que\nflota detr�s de la\ncascada cerca del\nmar de esmeralda.");
    WriteData((char*)0x1708BC0, "�Qu� es eso que\nbrilla en el agua?");
    WriteData((char*)0x1708C90, "�Destruye el molino y\ncontin�a! �Encuentra el\nglobo que est� flotando\nen el aire!");
    WriteData((char*)0x1708D60, "�Con qu� buen amigo est� el\nChao? �Y qu� es lo que hay\noculto debajo de �l?");
    WriteData((char*)0x1708E30, "�As� no me puedo duchar!\n�Haz algo!");
    WriteData((char*)0x1708F00, "Soy el guardi�n de este\nhotel. �Atr�pame si\npuedes!");
    WriteData((char*)0x1708FD0, "�El tornado se llev�\nvolando mis medallas!\n�Que alguien me ayude\na recuperarlas!");
    WriteData((char*)0x17090A0, "�Atrapa las banderas\nde las islas flotantes!");
    WriteData((char*)0x1709170, "�Apunta y dispara a\ntodas las medallas\ncon una bola Sonic!");
    WriteData((char*)0x1709240, "Por la noche, en el parque\nde atracciones, sincroniza tus\nsaltos sobre las plataformas.");
    WriteData((char*)0x1709310, "�Qu� es eso detr�s\ndel espejo?");
    WriteData((char*)0x17093E0, "�Recupera los globos en\nel tiempo dado! �Est�\nmuy resbaladizo!\n�Ve con cuidado!");
    WriteData((char*)0x17094B0, "�Protege a la mu�eca de\nSonic de los Spinners\nque la rodean!");
    WriteData((char*)0x1709580, "�Encuentra la bandera\nescondida en el pasaje\nsecreto bajo el\nmar de esmeralda!");
    WriteData((char*)0x1709650, "�Da la vuelta al caballo\nde madera y recoge\n10 globos!");
    WriteData((char*)0x1709720, "�Odio este asqueroso\ny oscuro lugar!�\n�Puedes encontrarlo?");
    WriteData((char*)0x17097F0, "�Qu� se esconde bajo la\ngarra derecha del le�n?");
    WriteData((char*)0x17098C0, "�Qu� es eso que\nprotegen los piratas\nen la punta del\nm�stil del barco?");
    WriteData((char*)0x1709990, "�Recoge 100 anillos y\nve hacia el helic�ptero!");
    WriteData((char*)0x1709A60, "Usa la fuente para atrapar el\nglobo durante el denso tr�fico\nde las ma�anas.");
    WriteData((char*)0x1709B30, "�Soy el guardi�n de este canal!\n�Atr�pame si puedes!");
    WriteData((char*)0x1709C00, "�Huy� un fugitivo\nde la c�rcel infernal!\n�Encuentra al fugitivo!");
    WriteData((char*)0x1709CD0, "�Atrapa el globo\nmientras flotas en\nel aire entre los\nescombros!");
    WriteData((char*)0x1709DA0, "�Puedes atrapar el globo\noculto bajo el puente?");
    WriteData((char*)0x1709E70, "�Sal disparado del ca��n\ny atrapa el globo!");
    WriteData((char*)0x1709F40, "�Puedes atrapar el globo\noculto bajo el puente?");
    WriteData((char*)0x170A010, "Soy el guardi�n de este\nlago helado. �A ver si\nme atrapas!");
    WriteData((char*)0x170A0E0, "Los cazas est�n volando por\ntodas partes. �Que alguien me\nsaque de aqu�!");
    WriteData((char*)0x170A1B0, "�Vuela sobre la jungla y\nconsigue todos los globos!");
    WriteData((char*)0x170A280, "Un mensaje de los ancestros:\nEn la direcci�n que\nindica la flecha que\narde ver�s...");
    WriteData((char*)0x170A350, "�Caza del tesoro en la\nplaya!\n�Encuentra las medallas\ndentro del tiempo l�mite!");
    WriteData((char*)0x170A420, "�Qu� se esconde\nen la zona hacia\ndonde mira la\nserpiente gigante?");
    WriteData((char*)0x170A4F0, "�Ten mucho cuidado justo\ncuando te caes por la\ncascada!");
    WriteData((char*)0x170A5C0, "No puedo entrar al\ncuarto de ba�o. �Que\nalguien me ayude!");
    WriteData((char*)0x170A690, "Fortaleza de acero.\nS�per salto en 3 caminos\nestrechos. Ten cuidado y no\nte caigas.");
    WriteData((char*)0x170A760, "�Soy el guardi�n de esta\nnave! �Atr�pame si puedes!");
    WriteData((char*)0x170A830, "�Ve al lugar en el que\nlos anillos representan\nla cara de Sonic!");
    WriteData((char*)0x170A900, "Una base secreta que est�\nllena de trampas mec�nicas.\nPresta atenci�n y puede\nque veas...");
    WriteData((char*)0x170A9D0, "�Consigue 10 globos en el\ncampo dentro del\ntiempo l�mite!");
    WriteData((char*)0x170AAA0, "�Puedes atrapar el\nglobo al que mira\nfijamente el Sonic\ngigante?");
    WriteData((char*)0x170AB70, "�Corre por la pista\na toda velocidad y\natrapa las banderas!");
    WriteData((char*)0x170AC40, "�Escoge una calle que\nse divide en 5 caminos\nantes de que se acabe\nel tiempo!");
    WriteData((char*)0x170AD10, "�Pistolero de Windy Valley!\n�Destruye todos los Spinners\ndentro del tiempo l�mite! ");
    WriteData((char*)0x170ADE0, "�Consigue 3 banderas en\nla selva dentro del\ntiempo l�mite!");
    WriteData((char*)0x170AEB0, "Salta por encima de\nla l�nea de anillos\ncon 3 S�per saltos\nen la pista de esqu�!");
    WriteData((char*)0x170AF80, "�Desciende en medio\nde la ventisca y\natrapa las banderas!");
    WriteData((char*)0x170B050, "�Desciende por el\nedificio y atrapa\ntodas las banderas!");
    WriteData((char*)0x170B120, "Hay erupciones continuas\nen el volc�n en llamas.\n�Qu� puede esconderse en\nel lugar donde ella est� mirando?");
    WriteData((char*)0x170B1F0, "�Pico de la monta�a volc�nica!\n�Cuidado con la lava!");
    WriteData((char*)0x170B2C0, "�La roca gigante te\nperseguir�! �Intenta\natrapar todas las banderas!");
    WriteData((char*)0x170B390, "�Cuidado con los\nbarriles y encuentra\nla bandera oculta en\nel contenedor!");
    WriteData((char*)0x170B460, "�Puedes encontrar la\nbandera dentro de la\ncabeza del dinosaurio?");
    WriteData((char*)0x170B530, "�Misi�n Completa!");
    WriteData((char*)0x170B600, "No disponible");
#pragma endregion

    char pathbuf[MAX_PATH];

    // Common PVRs
    ReplacePNG_Common("HYOJI_BALLS_E");
    ReplacePNG_Common("ST_064S_SCORE");
    // English stage PVRs
    ReplacePNG_StageE("A_STAGE01_E");
    ReplacePNG_StageE("A_STAGE02_E");
    ReplacePNG_StageE("A_STAGE03_E");
    ReplacePNG_StageE("B_STAGE01_E");
    ReplacePNG_StageE("B_STAGE02_E");
    ReplacePNG_StageE("B_STAGE03_E");
    ReplacePNG_StageE("B_STAGE04_E");
    ReplacePNG_StageE("E_STAGE01_E");
    ReplacePNG_StageE("E_STAGE02_E");
    ReplacePNG_StageE("E_STAGE03_E");
    ReplacePNG_StageE("E_STAGE04_E");
    ReplacePNG_StageE("E_STAGE05_E");
    ReplacePNG_StageE("K_STAGE01_E");
    ReplacePNG_StageE("K_STAGE02_E");
    ReplacePNG_StageE("K_STAGE03_E");
    ReplacePNG_StageE("K_STAGE04_E");
    ReplacePNG_StageE("K_STAGE05_E");
    ReplacePNG_StageE("M_STAGE01_E");
    ReplacePNG_StageE("M_STAGE02_E");
    ReplacePNG_StageE("M_STAGE03_E");
    ReplacePNG_StageE("M_STAGE04_E");
    ReplacePNG_StageE("M_STAGE05_E");
    ReplacePNG_StageE("ST_STAGE01_E");
    ReplacePNG_StageE("ST_STAGE02_E");
    ReplacePNG_StageE("ST_STAGE03_E");
    ReplacePNG_StageE("ST_STAGE04_E");
    ReplacePNG_StageE("ST_STAGE05_E");
    ReplacePNG_StageE("S_STAGE01_E");
    ReplacePNG_StageE("S_STAGE02_E");
    ReplacePNG_StageE("S_STAGE03_E");
    ReplacePNG_StageE("S_STAGE04_E");
    ReplacePNG_StageE("S_STAGE05_E");
    ReplacePNG_StageE("S_STAGE06_E");
    ReplacePNG_StageE("S_STAGE07_E");
    ReplacePNG_StageE("S_STAGE08_E");
    ReplacePNG_StageE("S_STAGE09_E");
    ReplacePNG_StageE("S_STAGE10_E");
    ReplacePNG_StageE("T_EGGCARRIER_E");
    ReplacePNG_StageE("T_MISTICRUIN_E");
    ReplacePNG_StageE("T_STATIONSQUARE_E");
}

__declspec(dllexport) void __cdecl OnFrame() {

    if (!CreditsLoaded)
    {
        if (DCconversion)
        {
         void LoadSA1DCCredits();
        }
        CreditsLoaded = true;
    }
}