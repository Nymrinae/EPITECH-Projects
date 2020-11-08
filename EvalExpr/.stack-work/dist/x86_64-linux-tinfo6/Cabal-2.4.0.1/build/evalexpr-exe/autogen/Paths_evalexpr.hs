{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_evalexpr (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/Nymrinae/Documents/Tek3/fun_evalexpr/.stack-work/install/x86_64-linux-tinfo6/6e0db8ce225ead59e6d58ed72ba28979bc544d2e6b4438cf4dc0dc137e7bd763/8.6.5/bin"
libdir     = "/home/Nymrinae/Documents/Tek3/fun_evalexpr/.stack-work/install/x86_64-linux-tinfo6/6e0db8ce225ead59e6d58ed72ba28979bc544d2e6b4438cf4dc0dc137e7bd763/8.6.5/lib/x86_64-linux-ghc-8.6.5/evalexpr-0.1.0.0-Fv9AJxvwpw6rJXV2AuENT-evalexpr-exe"
dynlibdir  = "/home/Nymrinae/Documents/Tek3/fun_evalexpr/.stack-work/install/x86_64-linux-tinfo6/6e0db8ce225ead59e6d58ed72ba28979bc544d2e6b4438cf4dc0dc137e7bd763/8.6.5/lib/x86_64-linux-ghc-8.6.5"
datadir    = "/home/Nymrinae/Documents/Tek3/fun_evalexpr/.stack-work/install/x86_64-linux-tinfo6/6e0db8ce225ead59e6d58ed72ba28979bc544d2e6b4438cf4dc0dc137e7bd763/8.6.5/share/x86_64-linux-ghc-8.6.5/evalexpr-0.1.0.0"
libexecdir = "/home/Nymrinae/Documents/Tek3/fun_evalexpr/.stack-work/install/x86_64-linux-tinfo6/6e0db8ce225ead59e6d58ed72ba28979bc544d2e6b4438cf4dc0dc137e7bd763/8.6.5/libexec/x86_64-linux-ghc-8.6.5/evalexpr-0.1.0.0"
sysconfdir = "/home/Nymrinae/Documents/Tek3/fun_evalexpr/.stack-work/install/x86_64-linux-tinfo6/6e0db8ce225ead59e6d58ed72ba28979bc544d2e6b4438cf4dc0dc137e7bd763/8.6.5/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "evalexpr_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "evalexpr_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "evalexpr_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "evalexpr_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "evalexpr_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "evalexpr_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
