/**
 * \file		Config.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant un modèle BaseConfig et ses dérivés.
 * \details		Une configuration permet de regrouper plusieurs données communes à un objet.
 *				Ces attributs sont public afin de permettre à l'utilisateur de les consulter
 *				et de les changer simplement (un ConfigUpdate sera sûrement nécessaire).
 * \todo		Créer une classe mère Configurable, ayant une fonction purement virtuelle
 *				ConfigUpdate mettant à jour l'objet héritant en fonction des changements faits 
 *				sur la configuration.
 */

#ifndef CONFIG
#define CONFIG

#include <string>
#include <iostream>

#include <SFML/Window.hpp>

#include "Utilities/Message/Msg.hpp"

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
	 * \class 	BaseConfig
	 * \brief 	Classe mère de toutes les configurations
	 */
	class BaseConfig
	{

		public:

			/**
			 * Récupération du nom de la configuration (purement virtuelle).
			 * \return 	Le nom de la configuration.
			 */
			virtual std::string GetName() const = 0;
			/**
			 * Impression des données de la configuration sur la sortie standard (purement virtuelle).
			 */
			virtual void Print() const = 0;

	};

	/**
	 * \class 	WindowConfig
	 * \brief 	Classe dérivée de BaseConfig et représentant la configuration d'une Sarah::Window::Window
	 * \see 	BaseConfig
	 * \todo 	Besoin d'une réflexion sur la nature conceptuelle de cette classe.
	 */
	class WindowConfig : public BaseConfig
	{

		public:

			/**
			 * Constructeur par défaut.
			 */
			WindowConfig():
				title("Default Window"),
				videoMode(sf::VideoMode(640, 480)),
				style(sf::Style::Default),
				contextSettings()
			{

			}

			/**
			 * Constructeur paramétré.
			 * \param 	p_title 	Titre de la fenêtre.
			 * \param 	p_videoMode	Mode vidéo utilisé (taille, etc.).
			 * \param 	p_style 	Style de la fenêtre (FullScreen, etc.).
			 * \param 	p_context 	ContextSettings de la fenêtre.
			 */
			WindowConfig(std::string p_title, sf::VideoMode p_videoMode, int p_style, sf::ContextSettings p_context):
				title(p_title),
				videoMode(p_videoMode),
				style(p_style),
				contextSettings(p_context)
			{
				
			}

			/**
			 * Redefinition de fonction GetName de BaseConfig
			 * \return 	WindowConfig
			 */
			std::string GetName() const
			{
				return "WindowConfig";
			}

			/**
			 * Redefinition de la fonction Print de BaseConfig
			 * \details	Imprime sur la sortie standard les attributs suivant un certain format
			 */
			void Print() const
			{
				bool styleMultiFlag = false;
				std::string styleStr = "", pipe = " | ", none = "";
				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "------------------------------");
				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, GetName());
				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "------------------------------");

				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "title \t\t-> ", title);
				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "videoMode \t-> ", videoMode.width, ":", videoMode.height, ":", videoMode.bitsPerPixel);

				if(style == 0)
					styleStr += "None";
				if(style & (1 << 0)){
					styleStr += (styleMultiFlag ? pipe : none) + "Titlebar";
					styleMultiFlag = true;
				}
				if(style & (1 << 1)){
					styleStr += (styleMultiFlag ? pipe : none) + "Resize";
					styleMultiFlag = true;
				}
				if(style & (1 << 2)){
					styleStr += (styleMultiFlag ? pipe : none) + "Close";
					styleMultiFlag = true;
				}
				if(style & (1 << 3)){
					styleStr += (styleMultiFlag ? pipe : none) + "FullScreen";
					styleMultiFlag = true;
				}
				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "style \t\t-> ", styleStr);

				msg::Msg_Spe(msg::MSG_FLAG_ENUM::GREEN, "contextSettings -> ", "à implémenter");
			}

		public:

			/**
			 * \brief 	Le titre de la fenêtre
			 */
			std::string 			title;

			/**
			 * \brief 	La taille de la fenêtre et le format des pixels (de type SFML VideoMode)
			 */
			sf::VideoMode 			videoMode;

			/**
			 * \brief 	Le style de la fenêtre (FullScreen, TitleBar, None, etc.)(enum SFML)
			 */
			int 					style;

			/**
			 * \brief 	Les informations de contexte de la fenêtre (de type SFML ContextSettings)
			 */
			sf::ContextSettings 	contextSettings;

	};

}
}

#endif
