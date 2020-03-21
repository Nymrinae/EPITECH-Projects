import React from 'react';

type PreferencesContextType = {
  theme: 'light' | 'dark'
  toggleTheme: () => void
};

export const PreferencesContext = React.createContext<PreferencesContextType>({
  theme: 'dark',
  toggleTheme: () => {}
});
