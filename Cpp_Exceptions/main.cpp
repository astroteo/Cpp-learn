#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;
class MyClass
{
public:
   void MyFunc(char c)
   {
      if(c < numeric_limits<char>::max())
         throw invalid_argument("MyFunc argument too large.");
      //...
   }
};

int main()
{
   try
   {
      MyFunc(256); //cause an exception to throw
   }

   catch(invalid_argument& e)
   {
      cerr << e.what() << endl;
      return -1;
   }
   //...
   return 0;
}

/*https://msdn.microsoft.com/it-it/library/hh279678.aspx

Eccezioni in C++ sono simili a quelle in linguaggi quali c# e Java. Nel try blocco, se un'eccezione generata sarà rilevata dal primo associata catch blocco il cui tipo corrisponde a quello dell'eccezione. In altre parole, l'esecuzione passa dal throw dell'istruzione di catch istruzione. Se viene rilevato alcun blocco catch utilizzabile, std::terminate viene richiamato e il programma viene chiuso. In C++, qualsiasi tipo può essere generato; Tuttavia, è consigliabile che si genera un tipo che deriva direttamente o indirettamente da std::exception. Nell'esempio precedente, il tipo di eccezione, invalid_argument, definita nella libreria standard nel < stdexcept> file di intestazione. C++ non fornisce e non richiede un finally blocco per assicurarsi che tutte le risorse vengano rilasciate se viene generata un'eccezione. L'acquisizione delle risorse è linguaggio inizializzazione (RAII), che utilizza i puntatori intelligenti, offre le funzionalità necessarie per la pulizia delle risorse. Per ulteriori informazioni, vedere procedura: progettare la sicurezza di eccezione del. Per informazioni sul meccanismo di rimozione dello stack C++, vedere eccezioni e rimozione dello Stack.

Linee guida di base
Gestione degli errori affidabile è problematico in qualsiasi linguaggio di programmazione. Anche se le eccezioni forniscono numerose funzionalità che supportano la gestione degli errori buona, essi non è in grado non tutto il lavoro. Per sfruttare i vantaggi del meccanismo di eccezione, tenere presenti le eccezioni in fase di progettazione del codice.

Utilizzare le asserzioni per verificare la presenza di errori che non devono mai verificarsi. Utilizzare le eccezioni per controllare gli errori che potrebbero verificarsi, ad esempio, errori di convalida dell'input per i parametri di funzioni pubbliche. Per ulteriori informazioni, vedere la sezione intitolata vs eccezioni. Asserzioni.

Utilizzare le eccezioni quando il codice che gestisce l'errore potrebbe essere separato dal codice che rileva l'errore da uno o più chiamate di funzione corrispondente. Considerare la possibilità di utilizzare i codici di errore nei cicli critiche per le prestazioni quando il codice che gestisce l'errore è strettamente collegato al codice che rileva. Per ulteriori informazioni sui casi di non utilizzare le eccezioni, vedere (NOTINBUILD) quando non utilizzare eccezioni.

Per ogni funzione che potrebbe generare o propaga un'eccezione, fornire uno di tre garanzie di eccezioni: la garanzia solida, la garanzia di base o la garanzia nothrow (noexcept). Per ulteriori informazioni, vedere procedura: progettare la sicurezza di eccezione del.

Generate eccezioni per valore e intercettarle per riferimento. Non si rilevano non è possibile gestire. Per ulteriori informazioni, vedere (NOTINBUILD) linee guida per la generazione e intercettazione di eccezioni (C++).

Non usare specifiche di eccezione, che sono deprecate in C++ 11. Per ulteriori informazioni, vedere la sezione intitolata specifiche di eccezione e noexcept.

Utilizzare i tipi di eccezione della libreria standard quando si applicano. Derivazione di tipi di eccezione personalizzata dalla classe eccezione gerarchia. Per ulteriori informazioni, vedere (NOTINBUILD) procedura: utilizzare gli oggetti eccezione della libreria Standard.

Non consentire eccezioni evitare i distruttori o funzioni di deallocazione di memoria.

Eccezioni e prestazioni
Il meccanismo delle eccezioni è ridotto al minimo sulle prestazioni se viene generata alcuna eccezione. Se viene generata un'eccezione, il costo dell'attraversamento dello stack e la rimozione è approssimativamente paragonabili al costo di una chiamata di funzione. Strutture di dati aggiuntivi sono necessarie per tenere traccia dello stack di chiamate dopo un try blocco viene immesso, e istruzioni aggiuntive sono necessarie per rimuovere lo stack, se viene generata un'eccezione. Tuttavia, nella maggior parte degli scenari, il costo delle prestazioni e footprint di memoria non è significativo. Effetti negativi delle eccezioni sulle prestazioni sono probabile che sia significativa solo nei sistemi molto memoria vincolata, o in prestazioni critiche cicli in cui è probabile che si verificano regolarmente un errore e il codice per risolvere il problema è strettamente collegato al codice che segnala. In ogni caso, è possibile conoscere il costo effettivo delle eccezioni senza profiling e la misurazione. Anche nei rari casi quando il costo è significativo, è possibile pesare contro la correttezza maggiore, più facile manutenibilità e altri vantaggi forniti da un criterio di eccezione ben progettata.

Eccezioni e le asserzioni
Eccezioni e le asserzioni vengono distinti due meccanismi per il rilevamento di errori di run-time in un programma. Utilizzare le asserzioni per verificare le condizioni in fase di sviluppo che non deve essere true se tutto il codice è corretto. Nessun punto di gestione l'errore utilizzando un'eccezione poiché l'errore indica che un elemento nel codice deve essere risolto e non rappresenta una condizione che il programma deve recuperare in fase di esecuzione. Un'istruzione assert interrompe l'esecuzione in corrispondenza dell'istruzione in modo che è possibile controllare lo stato del programma nel debugger. un'eccezione continua l'esecuzione dal primo gestore catch appropriata. Utilizzare le eccezioni per controllare le condizioni di errore che potrebbero verificarsi in fase di esecuzione anche se il codice sia corretto, ad esempio, "file non trovato" o "memoria esaurita." Si desidera ripristinare da queste condizioni, anche se il ripristino appena viene generato un messaggio a un registro e il programma verrà terminato. Controllare sempre gli argomenti per le funzioni pubbliche dall'utilizzo delle eccezioni. Anche se la funzione è privo di errori, si potrebbe non disporre il controllo completo sugli argomenti che un utente può passare a esso.

Eccezioni C++ e le eccezioni SEH di Windows
I programmi C e C++ è possono utilizzare il meccanismo (SEH) nel sistema operativo Windows di gestione delle eccezioni strutturata. I concetti presentati in SEH simili a quelle delle eccezioni C++, ad eccezione del fatto che utilizza SEH il __try, __except, e __finally costruisce anziché try e catch. In Visual C++, le eccezioni C++ sono implementate per SEH. Tuttavia, quando si scrive codice C++, utilizzare la sintassi di eccezione C++.

Per ulteriori informazioni su SEH, vedere gestione strutturata delle eccezioni (C/C++).

Noexcept e specifiche di eccezione
Specifiche di eccezione sono stati introdotti in C++ consente di specificare le eccezioni che potrebbe generare una funzione. Tuttavia, le specifiche di eccezione si è rivelato problematiche in pratica e sono deprecate in C++ 11 bozza di standard. Si consiglia di non utilizzare le specifiche di eccezione, ad eccezione di throw(), che indica che l'eccezione non consente eccezioni di escape. Se è necessario utilizzare le specifiche di eccezione del tipo throw(tipo), tenere presente che Visual C++ si allontana dallo standard in determinati modi. Per ulteriori informazioni, vedere specifiche di eccezione (generano). Il noexcept identificatore è stato introdotto in C++ 11 come l'alternativa migliore alla throw().

*/
