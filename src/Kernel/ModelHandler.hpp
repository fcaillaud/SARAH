/**
 * \file		ModelHandler.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe ModelHandler.
 * \detail 		Classe utilisée comme base de la stratégie MVC au sein de SARAH. Elle permet
 *				de gérer/regrouper les différentes structures de données et classes de traitement.
 *				Il est conseillé d'hériter de cette classe pour personnalisé son fonctionnement tout
 *				en usant de la structure qu'il forme avec GraphicHandler et ControlerHandler.
 */

#ifndef MODELHANDLER
#define MODELHANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "GeneralConfig.hpp"
#include "Observable.hpp"

/**
 * \namespace 	Sarah 	
 * \brief 		Nom de domaine principal.
 */
namespace Sarah
{

/**
 * \namespace 	Kernel	
 * \brief 		Nom de domaine secondaire, partie coeur.
 */
namespace Kernel
{

	/**
	 * \class 	ModelHandler
	 * \brief	Classe ModelHandler permettant de gérer toutes les structures de données et classes de traitement.
	 * \see 	GraphicHandler ControlerHandler
	 */
	class ModelHandler
	{

		/**
		 * \brief 	La classe ControlerHandler est en ami pour pouvoir accéder librement à ModelHandler.
		 * \todo 	Voir comment ne plus avoir besoin de cette amitié plus ou moins anormale.
		 */
		template<class M, class G, class E> friend class ControlerHandler;

		public:

			/*
			 * \fn 		Constructeur par défaut.
			 */
			ModelHandler();

			/*
			 * \fn 		Constructeur paramétré.
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_gConfig 	Objet représentant une configuration générale 
			 *						et avec lequel on initialise le controleur.
			 */
			ModelHandler(GeneralConfig &);

			/**
			 * \fn 		Destructeur.
			 */
			~ModelHandler();

			/**
			 * \fn 		Initialisation de la partie modèle de la plateforme SARAH (virtuelle).
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			virtual bool Init();

			/**
			 * \fn 		Chargement des modèles 2D, 3D et autres (virtuelle).
			 * \todo	Réfléchir à la vraie utilité de cette fonction.
			 * \return 	true si le chargement s'est bien passée, false sinon.
			 */
			virtual bool Load();

			/**
			 * \fn 		Notification de dessin généralement adressée à la Vue (virtuelle).
			 */
			virtual void Draw();

		public:

			/**
			 * \brief 	Configuration générale de la partie modèle de la plateforme.
			 * \detail 	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig 		gConfig;

		protected:

			/**
			 * \brief 	Horloge permettant un contexte temporel principal (de type SFML Clock).
			 */
			sf::Clock			m_generalClock;

	};

}
}

#endif
