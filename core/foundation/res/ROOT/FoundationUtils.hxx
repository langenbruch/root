/// \file FoundationUtils.hxx
///
/// \brief The file contains utilities which are foundational and could be used
/// across the core component of ROOT.
///
///
/// \author Vassil Vassilev <vvasilev@cern.ch>
///
/// \date June, 2019
///
/*************************************************************************
 * Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_CORE_FOUNDATION_FOUNDATIONUTILS_HXX
#define ROOT_CORE_FOUNDATION_FOUNDATIONUTILS_HXX

#include <string>

namespace ROOT {
namespace FoundationUtils {

   ///\returns the $PWD.
   std::string GetCurrentDir();

   ///\returns the relative path of \c path with respect to \c base.
   /// For instance, for path being "/a/b/c/d" and base "/a/b", returns "c/d".
   ///
   ///\param path - the input path
   ///
   ///\param base - the base path to be removed from \c path.
   ///
   ///\param isBuildingROOT - if true, it converts module directories such as
   ///                        core/base/inc/ to include/
   std::string MakePathRelative(const std::string &path, const std::string &base,
                                bool isBuildingROOT = false);

   ///\returns the path separator slash or backslash depending on the platform.
   inline const std::string& GetPathSeparator() {
#ifdef WIN32
      static const std::string gPathSeparator ("\\");
#else
      static const std::string gPathSeparator ("/");
#endif
      return gPathSeparator;
   }

   ///\returns the fallback directory in the installation (eg. /usr/local/root/).
   const std::string& GetFallbackRootSys();

   ///\returns the rootsys directory in the installation.
   ///
   const std::string& GetRootSys();

   ///\ returns the include directory in the installation.
   ///
   const std::string& GetIncludeDir();

   ///\returns the sysconfig directory in the installation.
   const std::string& GetEtcDir();

   } // namespace FoundationUtils
} // namespace ROOT

#endif // ROOT_CORE_FOUNDATION_FOUNDATIONUTILS_HXX
