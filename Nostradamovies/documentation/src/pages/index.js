import React from 'react';

import Layout from '@theme/Layout';
import Link from '@docusaurus/Link';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import styles from './index.module.css';

const HomePage = () => {
  return (
    <div className={styles.homePage}>
      <div>
        <div className={styles.homePageContent}>
          <h1>Nostradamovies</h1>
          <p>Make movie genre prediction with ease</p>
          <Link className="button button--primary button--lg" to="/docs">
            Get started
          </Link>
        </div>
      </div>
      <div>
        <div className={styles.homePageContent}>
          <img
            src={
              require('@site/static/img/searching-data-3d-illustration.png')
                .default
            }
            className={styles.homePageVisual}
          />
        </div>
      </div>
    </div>
  );
};

export default function Home() {
  return (
    <Layout>
      <HomePage />
    </Layout>
  );
}
