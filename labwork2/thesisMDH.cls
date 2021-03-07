%%%%%%%%%%%%%%%%%%%%%%%%%% INFORMATION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Master thesis template for Mälardalen University                             %
% Layout design: Mälardalen University                                         %
% Class creator: Emil Persson (epn17006@student.mdh.se)                        %
% Version:       1.0 (2020/05/03)                                              %
% Licence: CC BY-NC-SA 4.0 (https://creativecommons.org/licenses/by-nc-sa/4.0/)%  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% NOTICE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% \NewDocumentCommand and \DeclareDocumentCommand utilized are inspired by:    %
%   https://www.latextemplates.com/template/masters-doctoral-thesis            %
%   CC BY-NC-SA 3.0 (http://creativecommons.org/licenses/by-nc-sa/3.0/)        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\NeedsTeXFormat{LaTeX2e}
\newcommand{\classname}{thesisMDH}
\ProvidesClass{\classname}[2020/05/03 thesisMDH]
\LoadClass[a4paper, titlepage]{article}


\RequirePackage{graphicx}
\graphicspath{{images/}}
\RequirePackage{mathtools}
\RequirePackage{fancyhdr}
\RequirePackage{enumerate}
\RequirePackage{listings}
\RequirePackage[titletoc]{appendix}
\RequirePackage[margin=3cm]{geometry}
\RequirePackage[absolute]{textpos}
\RequirePackage[section]{placeins}
\RequirePackage{url}
\RequirePackage{tabularx}
\RequirePackage{caption}
\RequirePackage{float}
\RequirePackage{xcolor}


% Swedish language package 
\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage[swedish,british]{babel}

% Bibliography
\RequirePackage[style=ieee]{biblatex}
\RequirePackage{csquotes}


\RequirePackage{scrhack} % Loads packages fixes

\NewDocumentCommand{\thesisTitle} { o m }{%
 \IfValueTF{#1}{\def\shorttitle{#1}}{\def\shorttitle{#2}}%
 \def\@title{#2}%
 \def\theTitleName{\LARGE{\textbf{\uppercase{#2}}}}%
}
% \DeclareDocumentCommand{\author}{m m}{
% \newcommand{\authorName}{\LARGE{#1} \\ \large{#2}}\renewcommand{\@author}{#1}}

\NewDocumentCommand{\authorOne}{m m}{
\newcommand{\authorOneName}{\Large{#1} ({#2})}}

\NewDocumentCommand{\authorTwo}{m m}{
\newcommand{\authorTwoName}{\Large{#1} ({#2})}}

\NewDocumentCommand{\authorThree}{m m}{
\newcommand{\authorThreeName}{\Large{#1} ({#2})}}

\NewDocumentCommand{\authorFour}{m m}{
\newcommand{\authorFourName}{\Large{#1} ({#2})}}

\NewDocumentCommand{\authorFive}{m m}{
\newcommand{\authorFiveName}{\Large{#1} ({#2})}}

\NewDocumentCommand{\authorSix}{m m}{
\newcommand{\authorSixName}{\Large{#1} ({#2})}}

\NewDocumentCommand{\subject}{m}{\newcommand{\subjectName}{\LARGE{#1}}}
\NewDocumentCommand{\university}{m}{\newcommand{\uniName}{\Large{#1}}}
\NewDocumentCommand{\department}{m}{\newcommand{\depName}{\Large{#1}}}
\NewDocumentCommand{\degree}{m}{\newcommand{\degreeName}{\Large{#1}}}


\NewDocumentCommand{\examiner}{m m}{
\newcommand{\examName}{\large{Examiner: #1} \\ \small{#2}}}

\NewDocumentCommand{\supervisors}{m m}{
\newcommand{\superName}{\Large{\textbf{Supervisor: #1}} \\ \large{#2}}}

\NewDocumentCommand{\companySupervisors}{m m}{
\newcommand{\compSuperName}{\large{Company Supervisor(s): #1} \\ \small{#2}}}

\NewDocumentCommand{\theDate}{m}{\newcommand{\datum}{\vspace*{\fill}\large #1}}

\newcommand{\warning}[1]{\centering{\textcolor{red}{\large{\textbf{\uppercase{#1\\}}}}}}
\newcommand{\alert}[1]{\textcolor{red}{\textit{\scriptsize\textbf{\uppercase{#1}}}}}


% \newcommand{\moderator}[2]{
%   \Large{#1}: 
%     \begin{minipage}[t]{0,7\textwidth}
%         \large{#2}\\
%     \end{minipage}\\[0.5cm] 
%   }
  
\newcommand{\titlePage}{
    \begin{titlepage}
        \begin{center}
    		
            \ifdef{\uniName}{\vspace{-5mm}\uniName\\}{\warning{Missing university name}}
            \vspace{5mm}
            
            % \ifdef{\depName}{\depName\\}{\warning{Missing department name}} 
            \includegraphics[scale=0.5]{images/logo.png}
            
            % \noindent\makebox[\linewidth]{\rule{\textwidth}{0.4pt}} \\
            \vspace{20mm}
            
            \ifdef{\subjectName}{\subjectName}{\warning{Missing course name}} \\
            \vspace{5mm}
            
    		\ifdef{\theTitleName}{\theTitleName}{\warning{Missing title}} \\
    		\vspace{20mm}
    		
    		{\textbf{Group members:}\\ \vspace{5mm}}
    		\ifdef{\authorOneName}{\authorOneName \\ \vspace{5mm}}{\warning{Missing authorOne}} 
    		
    		\ifdef{\authorTwoName}{\authorTwoName \\ \vspace{5mm}}{}
    		
    		\ifdef{\authorThreeName}{\authorThreeName \\ \vspace{5mm}}{}
    		
    		\ifdef{\authorFourName}{\authorFourName \\ \vspace{5mm}}{}
    		
    		\ifdef{\authorFiveName}{\authorFiveName \\ \vspace{5mm}}{}
    		
    		\ifdef{\authorSixName}{\authorSixName \\}{}

            \vspace{15mm}
            % \begin{flushleft}
            
                \ifdef{\examName}{\examName \\ \vspace{5mm}}{}
                
                \ifdef{\superName}{\superName \\ \vspace{5mm}}{}
                
                \ifdef{\compSuperName}{\compSuperName \\}{}
                
            % \end{flushleft}
            \vfill
            \ifdef{\datum}{\datum}{\vspace*{\fill}\warning{Missing date}}
        \end{center}
    \end{titlepage}
}


% Set font
%\setromanfont{Calibri}
\renewcommand\contentsname{Table of Contents}
\newcommand{\HRule}{\rule{\linewidth}{0.5mm}}

\newcommand{\circR}{\textsuperscript{\textregistered}}
% set the style for the section and subsection headers
\renewcommand{\thesection}{\thepart \arabic{section}.}
\renewcommand{\thesubsection}{\thepart \arabic{section}.\arabic{subsection}}

\makeatletter

\newcommand\frontmatter{%
    \cleardoublepage
  %\@mainmatterfalse
  \pagenumbering{roman}}

\newcommand\mainmatter{%
    \cleardoublepage
 % \@mainmattertrue
  \pagenumbering{arabic}}

\newcommand\backmatter{%
  \if@openright
    \cleardoublepage
  \else
    \clearpage
  \fi
 % \@mainmatterfalse
  }

\makeatother

\renewenvironment{abstract}{
  \begin{center}%
  \bfseries\abstractname\vspace{-.5em}\vspace{0pt}
  \end{center}
  \itshape
}

% Code style
\definecolor{dkgreen}{rgb}{0,0.6,0}
\definecolor{gray}{rgb}{0.5,0.5,0.5}
\definecolor{mauve}{rgb}{0.58,0,0.82}

\lstset{
  frame=tb,
  language=C,
  aboveskip=3mm,
  basicstyle={\small\ttfamily},
  belowskip=3mm,
  breaklines=true,
  breakatwhitespace=true,
  columns=flexible,
  commentstyle=\color{gray},
  keywordstyle=\color{blue},
  numbers=none,
  numberstyle=\tiny\color{gray},
  showstringspaces=false,
  stringstyle=\color{mauve},
  tabsize=3,
}

% Page style
% \pagestyle{fancy}
\marginparsep = 0pt

\newcommand{\fancyHeader}[2]{
\thispagestyle{fancy}
\fancyhead[R]{#1}
\fancyhead[L]{#2}
% \fancyfoot[L]{}
%\fancyfoot[LE,RO]{\thepage}
\renewcommand{\headrulewidth}{0.4pt}
\renewcommand{\footrulewidth}{0.4pt}
}

\endinput