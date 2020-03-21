import React from 'react';
import {
  Provider as PaperProvider,
  DefaultTheme,
  DarkTheme,
} from 'react-native-paper';

import { useColorScheme } from 'react-native-appearance';

import DrawerNavigator from './DrawerNavigator';
import { PreferencesContext } from '../types/preferences';

const RootNavigator = () => {
  const colorScheme = useColorScheme();
  const [theme, setTheme] = React.useState<'light' | 'dark'>(
    colorScheme === 'dark' ? 'dark' : 'light'
  );

  function toggleTheme() {
    setTheme(theme => (theme === 'light' ? 'dark' : 'light'));
  }

  const preferences = React.useMemo(
    () => ({
      toggleTheme,
      theme,
    }),
    [theme]
  );

  return (
    <PreferencesContext.Provider value={preferences}>
      <PaperProvider
        theme={
          theme === 'light'
            ? {
                ...DefaultTheme,
                colors: { ...DefaultTheme.colors, primary: 'black' },
              }
            : {
                ...DarkTheme,
                colors: { ...DarkTheme.colors, primary: 'white' },
              }
        }
      >
        <DrawerNavigator />
      </PaperProvider>
    </PreferencesContext.Provider>
  )
}

export default RootNavigator